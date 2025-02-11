# PWM

## Descrição

Este repositório contém os códigos correspondentes aos requisitos solicitados pela tarefa 1 do capítulo 4 da unidade 7 do programa de capacitação em sistemas embarcados (Embarcatech). A tarefa em questão busca incitar a utilização de Pulse Width Modulation (PWM) para controlar o movimento de um servomotor e a intensidade de um LED.

## Requerimentos

O presente projeto deverá atender aos seguintes requerimentos:

* Considerando a GPIO 22, defina a sua frequência de PWM para, aproximadamente, 50Hz – período de 20ms.

* Defina o ciclo ativo do módulo PWM para 2.400µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,12%. isto ajustará a flange (braço) do servomotor para a posição de, aproximadamente, 180 graus. Aguarde 05 segundos nesta posição. 

* Defina o ciclo ativo do módulo PWM para 1.470µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,0735%. Isto ajustará a flange do servomotor para a posição de, aproximadamente, 90 graus. Aguarde 05 segundos nesta posição.

* Defina o ciclo ativo do módulo PWM para 500µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,025%. Isto ajustará a flange do servomotor para a posição de, aproximadamente, 0 graus. Aguarde 05 segundos nesta posição.

* Após a realização das proposições anteriores, crie uma rotina para movimentação periódica do braço do servomotor entre os ângulos de 0 e 180 graus.  Obs.: a movimentação da flange deve ser suave, recomenda-se o incremento de ciclo ativo de ±5µs, com um atraso de ajuste de 10ms.

* Com o emprego da Ferramenta Educacional BitDogLab, faça um experimento com o código deste exercício utilizando o LED RGB – GPIO 12. O que o discente observou no comportamento da iluminação do referido LED? (15% da nota) 

## Demonstração

Segue o vídeo de demonstração do projeto:

https://github.com/user-attachments/assets/e907c12b-7fea-45cb-bc5e-789ccc460548

## Instruções

Para que o projeto funcione em sua máquina, é necessário ter a extensão Raspberry Pi Pico Project instalada no VSCode.

1. Realize o clone do repositório.
2. Importe o repositório como um projeto através da extensão Raspberry Pi Pico Project.
3. Compile o projeto.
4. Caso esteja usando a placa BitDogLab ou a Raspberry Pi Pico W, faça o upload do arquivo uf2, encontrado na pasta `build` após o processo de compilação, para a placa. Caso deseje simular, abra o arquivo `diagram.json` (É necessário ter a extensão do Wokwi instalada).
