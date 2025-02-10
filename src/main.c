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
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
