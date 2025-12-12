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
| Jeferson Almeida     | Projetista                   | [@Jeferson](https://github.com/JefersonAlmeid4)  |


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

### Semana 4: (17/10/2025)

**Foco da Semana:** Testar código de calibração desenvolvido.

  * **Software:**
      * **Código:** Testado código de calibração e detectado alguns problemas. 
  * **Próximos Passos:**
      * Analisar novamente o código de calibração.
      * Verificação do robô 2.
   
### Semana 5: (01/11/2025)

**Foco da Semana:** Atualizar código de calibração.

  * **Software:**
      * **Código:** Resolvidos problemas no código de calibração e código atualmente está funcional. 
  * **Próximos Passos:**
      * Pesquisar sobre módulo carregador.
      * Verificação do robô 2.
   
### Semana 6: (12/11/2025)

**Foco da Semana:** Iniciar processo de soldagem dos componentes do módulo carregador.

  * **Hardware & Modelagem 3D:**
      * **Soldagem:** Foram soldados os fios necessários para fazer a inserção do módulo carregador: conexões entre a bateria, módulo carregador e Step-Up. 
  * **Próximos Passos:**
      * Finalizar soldagem.
      * Replicar para o segundo módulo.
   
 ### Semana 7: (19/11/2025)

**Foco da Semana:** Finzalizar soldagem dos componentes do primeiro módulo carregador.

  * **Hardware & Modelagem 3D:**
      * **Soldagem:** Foi finalizada a soldagem do primeiro módulo carregador. 
  * **Próximos Passos:**
      * Carregar módulo.
      * Realizar testes no robô, verificando se está alimentando o sistema e se o carregamento ocorreu bem.
      * Replicar para o segundo módulo.

### Semana 8: (24/11/2025)

**Foco da Semana:** Realizar a solda do segundo módulo carregador.

  * **Hardware & Modelagem 3D:**
      * **Soldagem:** Foram soldadas 2 novas baterias em série, já que a bateria anterior do projeto foi reutilizada pelo RAS. As conexões de fios entre o módulo carregador e as baterias também foram feitas pela solda. 
  * **Próximos Passos:**
      * Finalizar soldagem, inserindo o componente do Step-Up.
      * Carregar e verificar ambos os 2 módulos carregadores.
      * Realizar testes dos 2 módulos para os 2 robôs.

### Semana 9: (01/12/2025)

**Foco da Semana:** Realizar a solda do segundo módulo carregador, testar na ponte H e tirar fotos para apresentação.

  * **Hardware & Modelagem 3D:**
      * **Soldagem:** Foi finalizado a solda do segundo módulo carrgeador, apesar de haver algumas pendências.
      * **Teste:** Foi testado se o primeiro módulo iria carregar o projeto. Quando conectado a ponte H, foi visto que ele conseguia alimentar o sistema.
  * **Outros:**
      * Apresentação:** Foram tiradas fotos e gravados vídeos de como o projeto estava, a fim de serem materiais para se colocar na apresentação do projeto. 
  * **Próximos Passos:**
      * Testar o segundo módulo, em especial, verificar sobre as baterias, já que uma indicou voltagem próxima a 0V.
      * Calibrar o segundo Step-Up.
      * Carregar ambos os 2 módulos carregadores.
      * Resolver possíveis pendências no quesito na ordem dos componentes (ver com Mike).
---

## 🚀 Como Contribuir

Somos um projeto de código e hardware abertos\! Se você deseja contribuir:

1. **Faça um Fork** deste repositório.
2. **Crie uma Branch** para sua feature (`git checkout -b feature/SuaFeature`).
3. **Faça o Commit** de suas mudanças (`git commit -m 'Adiciona SuaFeature'`).
4. **Faça o Push** para a Branch (`git push origin feature/SuaFeature`).
5. Abra um **Pull Request**.

Para problemas ou sugestões, por favor, abra uma **Issue**.
