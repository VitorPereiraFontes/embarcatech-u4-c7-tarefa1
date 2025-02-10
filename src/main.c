#include <stdio.h>
#include "pico/stdlib.h"
#include "pwm.h"

// Para o experimento com o LED, troque a GPIO pela 11, 12 ou 13
#define SERVO_PIN 12 // Define a GPIO utilizada para conectar-se ao servomotor
#define PWM_CLOCK_DIVISOR 64.0 // Define a parte inteira e fracionada do divisor para o maior valor possível
#define PWM_WRAP 39062 // Define o wrap do PWM para que a frequência seja de 50Hz
#define SERVO_INTERVAL 5000 // Intervalo, em milissegundos, entre as rotações do servomotor
#define DUTY_CYCLE_ORIGIN 0.025 // % do duty cycle que corresponde ao braço na origem
#define DUTY_CYCLE_90 0.075 // % do duty cycle que corresponde ao braço em 90 graus
#define DUTY_CYCLE_180 0.12 // % do duty cycle que corresponde ao braço em 180 graus

bool start = true; // Variável que controla se é a primeira vez que o programa está executando
bool raise = false; // Variável para controlar se o braço do servomotor irá abrir ou fechar a angulação em relação à origem
float current_duty = DUTY_CYCLE_ORIGIN; // Informa o duty cycle atual
float duty_step = 0.00025; // Variável que informa o quando será incrementado/decrementado o duty cycle

int main()
{
    stdio_init_all(); // Inicializa as entradas e saídas padrão

    while (true) {
        if(start){
            // Configura o PWM para operar num duty cycle de 12%, de modo que o braço do motor se desloque para um ângulo de 180 graus em relação à origem
            setup_pwm(SERVO_PIN,PWM_CLOCK_DIVISOR,PWM_WRAP,get_duty_cycle(PWM_WRAP,0.12)); 

            sleep_ms(SERVO_INTERVAL); // Aguarda 5 segundos

            // Configura o PWM para operar num duty cycle de 7,5%, de modo que o braço do motor se desloque para um ângulo de 90 graus em relação à origem
            setup_pwm(SERVO_PIN,PWM_CLOCK_DIVISOR,PWM_WRAP,get_duty_cycle(PWM_WRAP,0.075));
        
            sleep_ms(SERVO_INTERVAL); // Aguarda 5 segundos

            // Configura o PWM para operar num duty cycle de 2,5%, de modo que o braço do motor se desloque para a origem
            setup_pwm(SERVO_PIN,PWM_CLOCK_DIVISOR,PWM_WRAP,get_duty_cycle(PWM_WRAP,0.025));

            sleep_ms(SERVO_INTERVAL); // Aguarda 5 segundos

            start = false; // Muda a variável de controle para falso, indicando que a primeira parte do controle do servomotor terminou
        }

        if(raise){
            current_duty = current_duty - duty_step; // Decrementa o duty cycle

            // Atualiza o duty cycle
            setup_pwm(SERVO_PIN,PWM_CLOCK_DIVISOR,PWM_WRAP,get_duty_cycle(PWM_WRAP,current_duty)); // Atualiza a posição do braço do servomotor

            // Verifica se o braço já alcançou a origem, caso positivo, troca o valor da variável de controle
            if(current_duty < DUTY_CYCLE_ORIGIN){
                raise = false;
            }
        }else{
            current_duty = current_duty + duty_step; // Incrementa o duty cycle

            // Atualiza o duty cycle
            setup_pwm(SERVO_PIN,PWM_CLOCK_DIVISOR,PWM_WRAP,get_duty_cycle(PWM_WRAP,current_duty));

            // Verifica se o braço já alcançou o ângulo de 180 graus em relação à origem, caso positivo, troca o valor da variável de controle
            if(current_duty > DUTY_CYCLE_180){
                raise = true;
            }
        }

        sleep_ms(10); // Aguarda 10 milissegundos
    }
}
