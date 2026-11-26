# 🏴‍☠️ Transformações Lineares em C — Computação Gráfica e Jogos

Repositório dedicado à implementação em linguagem **C** de algoritmos de **Transformações Lineares** aplicados ao processamento de imagens digitais e à movimentação de personagens em ambientes bidimensionais (2D).

* **Instituição:** CEUB — Engenharia de Software
* **Tema:** Transformações Lineares

---
* [PiratariaAL]( https://rafaelbarros831.github.io/Rotation_Sprites_2D/)
---
## 🗺️ Mapa Pirata do Sistema (Fluxo de Execução)

```text
[ X ] Porto de Partida: main()
  │
  ├──► Rota 1: Processamento de Imagens Digitais (Escala)
  │      ├── 1. Coleta 5 coordenadas (x, y) da imagem
  │      ├── 2. Solicita o fator de escala (k) ao usuário
  │      ├── 3. Aplica a matriz de escala: T(x, y) = [ k*x, k*y ]
  │      └── 4. Exibe tabela comparativa (Original vs. Transformada)
  │
  └──► Rota 2: Rotação de Personagens em Jogos 2D
         ├── 1. Recebe as coordenadas (x, y) de um ou mais personagens
         ├── 2. Aplica a matriz de rotação A (90°, 180° e 270° anti-horário)


         └── 3. Apresenta o comparativo entre as posições iniciais e rotacionadas
```
