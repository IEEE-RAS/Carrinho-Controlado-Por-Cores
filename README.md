# 🤖 [Robô Orientado por Cores] - Diário de Desenvolvimento

**Equipe:** IEEE RAS - UEFS

## 📝 Visão Geral

Este repositório serve como o diário de desenvolvimento oficial do projeto **Robô Orientado por Cores**. Nosso objetivo é atualizar e melhorar o antigo projeto do robô orientado por cores. Aqui, documentamos nosso progresso, desafios e aprendizados em todas as frentes: software, hardware, eletrônica e design mecânico.

## 👥 Equipe

| Nome                 | Cargo no projeto             | GitHub                                           |
| -------------------- | -------------------------    | ------------------------------------------       |
| Victor Ariel         | Líder de Projeto             | [@Victor](https://github.com/VitrolaVT)          |
| Nicassio             | Projetista                   | [@Nicassio](https://github.com/nicassiosantos)   |
| Daniel Braz          | Projetista                   | [@Daniel](https://github.com/DanielPortoBraz)    |
| Allany Victória      | Projetista                   | [@Allany](https://github.com/allanyvictoria)     |
| Alisson Wilker       | Projetista                   | [@Alisson](https://github.com/alissonwilker02)   |

## 🎯 Metas do Projeto

### Metas atuais

  * **Hardware:** Acomplar módulo carregador para bateria e deixar projeto mais profissional.
  * **Software:** Calibrar sensor para cores e calibrar velocidade dos motores.

### Objetivos Gerais

  - **Hardware:**
      - [ ] Melhorar chassi para deixar mais estético, organizado e profissional.
      - [ ] Integrar módulo carregador.
  - **Software:**
      - [ ] Desenvolver um sistema de calibração do sensor de forma flexível e versátil a depender do ambiente e sua iluminação.
      - [ ] Implementar lógica para controle das velocidades de cada motor através do controle PWM da ponte H.

## 🛠️ Tecnologias e Ferramentas

| Categoria         | Ferramentas                                                              |
| ----------------- | ------------------------------------------------------------------------ |
| **Linguagens**    | C++                                                                      |
| **Frameworks**    |...                                                                       |
| **Hardware**      | Arduino UNO R3 (WAVGATE), Sensor TCS3200, Ponte H L298N,  Motores        |
| **Modelagem 3D**  | ...                                                                      |
| **Design de PCB** | ...                                                                      |
| **Simulação**     | ...                                                                      |

-----

## 📓 Diário de Desenvolvimento

Aqui registramos nosso progresso semanalmente. Cada entrada inclui atualizações de hardware e software, os desafios que encontramos e as decisões que tomamos.

### Semana 1: (22/09/2025)

**Foco da Semana:** Planejamento Inicial e Análise da condição do projeto

  * **Software:**
      * **Código:** Início do código para adquirir valores das cores RGB com base na análise do ambiente que se encontra. 
  * **Hardware & Modelagem 3D:**
      * **Eletrônica:** Verificamos a integridade das conexões e componentes.
  * **Decisões:**
      * Elencamos as melhorias propostas.
  * **Próximos Passos:**
      * Verificar o erro no qual a roda esquerda não gira.
      * Continuar código da calibração para tomada da decisão de movimento do robô.

### Semana 2: (29/09/2025)

**Foco da Semana:** Corrigir problema da roda esquerda não rodar.

  * **Software:**
      * **Código:** Estudo de como alterar velocidade dos motores através da função *analogWrite()* para pinos com capacidade de PWM.
  * **Hardware & Modelagem 3D:**
      * **Eletrônica:** Verificado que a falta de rolagem da roda esquerda advém do pino *ENB* da ponte H que não está conectada. 
  * **Próximos Passos:**
      * Dar retoques finais no robô 1.
      * Verificar o robô 2, uma vez que foi devolvida a ponte H do mesmo.
      * Implementar lógica da mudança da velocidade dos motores.

### Semana 3: (06/10/2025)

**Foco da Semana:** Aperfeiçoar o robô para Feira de Graduação.

  * **Software:**
      * **Código:** Implementado a lógica de redução de velocidade (branch *Calibracao-Velocidade*) e ajustes nos valores usados para detecção de cor para permitir apresentação na feira.
  * **Hardware & Modelagem 3D:**
      * **Eletrônica:** Uso de 2 novos fios para usar o PWM, permitindo o uso de velocidades variadas. 
  * **Próximos Passos:**
      * Dar retoques finais no robô 1.
      * Verificar o robô 2, uma vez que foi devolvida a ponte H do mesmo.
      * Testar novo código de calibração do sensor/cor.

---

## 🚀 Como Contribuir

Somos um projeto de código e hardware abertos\! Se você deseja contribuir:

1. **Faça um Fork** deste repositório.
2. **Crie uma Branch** para sua feature (`git checkout -b feature/SuaFeature`).
3. **Faça o Commit** de suas mudanças (`git commit -m 'Adiciona SuaFeature'`).
4. **Faça o Push** para a Branch (`git push origin feature/SuaFeature`).
5. Abra um **Pull Request**.

Para problemas ou sugestões, por favor, abra uma **Issue**.
