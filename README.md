# 🤖 [Robô Orientado por Cores] - Diário de Desenvolvimento

**Equipe:** IEEE RAS - UEFS

## 📝 Visão Geral

Este repositório serve como o diário de desenvolvimento oficial do projeto **Robô Orientado por Cores**. Nosso objetivo é atualizar e melhorar o antigo projeto do robô orientado por cores. Aqui, documentamos nosso progresso, desafios e aprendizados em todas as frentes: software, hardware, eletrônica e design mecânico.
> Um manual de uso de como carregar e os passos para usar os códigos do robô estarão no final desse diário de bordo.

## 👥 Equipe

| Nome                 | Cargo no projeto             | GitHub                                           |
| -------------------- | -------------------------    | ------------------------------------------       |
| Victor Ariel         | Líder de Projeto             | [@Victor](https://github.com/VitrolaVT)          |
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
| **Hardware**      | Arduino UNO R3 (WAVGATE), Sensor TCS3200, Ponte H L298N,  Motores, Baterias de Lítio (2), Step-Up MT3608, Módulo Carregador TP4056|
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
   
### Semana 10: (27/04/2026)

**Foco da Semana:** Verificar código da calibração da velocidade, ajustar ordem dos componentes e tirar medidas do carrinho.

  * **Hardware & Modelagem 3D:**
      * **Soldagem:** Foi ajustado e soldado as peças do sistema do módulo carregador, faltando conectar botão.
      * **Teste:** Foi testado se o sistema ainda continua funcional. Resultados: Funciona normalmente.
      * **Medição:** Foi tiradas medidas do carrinho:
        * **Rodas (Diâmetro):** 6,7 cm
        * **Largura (Horizontal):** 10,1 cm
        * **Comprimento (Vertical):** 21 cm
        * **Altura (Placa - Ponta da roda traseira):** 4,8 cm
  * **Próximos Passos:**
      * Finalizar conexões faltantes do botão no módulo trabalhado.
      * Unir códigos de calibração do sensor com da calibração da velocidade.
  
### Semana 11: (07/05/2026)

**Foco da Semana:** Finalizar conexão do botão no módulo carregador e iniciar união dos códigos de calibração.

  * **Hardware & Modelagem 3D:**
      * **Soldagem:** Foi finalizada a soldagem do botão ao sistema do módulo carregador. Problema encontrado: Falta de solda na S10.
  * **Software:**
      * **Calibração:** Foi feito um teste usando um esboço do código já com a união das partes de calibração da velocidade e do sensor. Resultados: O teste passou normalmente usando o *SerialPrintln* da IDE, porém como foi conectado via o cabo, não foi possível testar a movimentação das rodas usando PWM.
  * **Próximos Passos:**
      * Testar carregamento do sistema do módulo carregador.
      * Corrigir novo código de calibração e testá-lo usando bateria conectada.
   
### Semana 12: (22/05/2026)

**Foco da Semana:** Carregamento da bateria e atualizar código da calibração do sensor + PWM.

  * **Software:**
      * **Calibração:** O novo código de calibração do sensor de cor e uso do PWM foi atualizado.
   * **Outros:**
     * **Carregamento:** Bateria foi carregada até 3.8 V.
  * **Próximos Passos:**
      * Testar o novo código usando a alimentação da própria bateria em vez do *"SerialPrintln"*.

### Semana 13: (29/05/2026)

**Foco da Semana:** Teste do novo código juntamente com a bateria carregada e Manual de Uso no README.

  * **Software:**
      * **Calibração:** Foi realizado o teste para as novas integrações. Resultado: Teste seguiu como desejado.
   * **Outros:**
     * **Manual de Uso:** Adicionado no fim desse diário de bordo um manual de como carregar as baterias e de como calibrar o sensor.
  * **Próximos Passos:**
      * A decidir na próxima reunião.

 ### Semana 14: (31/05/2026)

**Foco da Semana:** Reunião remota para discutir próximos passos do projeto.

   * **Hardware & Modelagem 3D:**
      * **Tarefas:**
          * 1- Esboço da modelagem 3D, deve ser completo, pensado como "carcaça/casca" do robô. OBS: Deve considerar como visualmente o robô será; Deve considerar o espaço para acomodar bateria; Deve considerar saídas do módulo carregador e do interruptor; Deve ser compacto.
          * 2- Organizar espaço destinado aos componentes. Possível organização: I-Arduino colado no topo (mesma posição de antes); II- Kit Bateria no meio (step-up logo abaixo da bateria, em contato com a Ponte H); III- Ponte H rotacionada (trocou as saídas de alimentação das rodas); IV - Organizar fios/jumpers para ficarem compactos.
          * 3- Organizar especificamente o Kit Bateria, deixando mais compacto e seguindo a organização do espaço destinado no chassi. OBS: Implementar do zero esse kit para osegundo robô. Peças usadas: Bateria de lítio em paralelo, Step-Up, Módulo carregador (já está na caixa) e Interruptor (já está na caixa).

     
        > **Observação:** As tarefas serão aplicadas no segundo robô a níveis de prototipagem.
     
      * **Divisão:**
          * 1- Modelagem 3D - Daniel;
          * 2- Organização dos componentes - Jeferson;
          * 3- Implementação do 2º Kit Bateria - Victor.
             
  * **Próximos Passos:**
      * Organização individual de cada integrante para implementar sua tarefa.

### Semana 15: (12/06/2026)

**Foco da Semana:** Organização inicial do segundo robô e implementação do segundo Kit Bateria.

  * **Hardware & Modelagem 3D:**
      * **Organização:** Foi feito a organização inicial dos jumpers/fios do robô.
      * **Soldagem:** Foi organizado os materiais necessários para soldagem do Kit Bateria e configuração do Step-Up.
  * **Próximos Passos:**
      * Continuação da organização e soldagem dos componentes no Kit Bateria.

### Semana 16: (30/06/2026)

**Foco da Semana:** Soldagem final do Kit Bateria.

  * **Hardware & Modelagem 3D:**
      * **Soldagem:** Foi finalizada a soldagem da bateria no Kit Bateria.
  * **Próximos Passos:**
      * Fazer camadas de proteção dos componentes;
      * Finalizar organização dos jumpers faltantes;
      * Carregar e testar o robô.

### Semana 17: (06/07/2026)

**Foco da Semana:** Finalizar organização dos jumpers, aplicar camadas de proteção dos componentes no Kit Bateria e carregar a bateria.

  * **Hardware & Modelagem 3D:**
      * **Organização:** Foi finalizada a organização dos jumpers no robô; Foi feita camadas de proteção dos componentes; Carregou um pouco a bateria.
  * **Próximos Passos:**
      * Realizar testes e correções finais;
      * Acoplar o chassi em modelo 3D no robô.

### Semana 18: (08/07/2026)

**Foco da Semana:** Ajuste dos pinos dos motores, ajuste da velocidade para cada motor e testes da nova arquitetura.

  * **Software:**
    * **Calibração:** Correção dos pinos usados para os 2 motores, uma vez que estavam trocados com a mudança da organização da ponte H; Ajuste fino da velocidade para cada motor; Testes feitos usando código de calibração da velocidade (sem uso de calibração manual do sensor de cor) para o robô 2.
  * **Próximos Passos:**
      * Atualizar código principal com calibração do sensor de cor, a fim de acomodar a nova arquitetura e ordem dos componentes;
      * Acoplar o chassi em modelo 3D no robô.
---
## 📖 Manual de Uso

### 🔋 Como carregar a bateria

Os passos para carregamento do sistema são:

1. Configure a fonte de bancada para tensão de **5 V** e corrente entre **1 A e 2 A** (recomendação: **1.2 A**).

2. Conecte a entrada positiva da fonte na entrada **"+" (Vin+)** do módulo carregador e a saída negativa da fonte na saída **"-" (Vout-)** do módulo carregador.

3. Verifique se o interruptor do sistema está desligado — posição **"O"**.

4. Ao ligar a fonte, deve acender um **LED vermelho** no módulo carregador, indicando que o sistema está carregando.

5. Quando o carregamento estiver concluído, irá acender um **LED verde** no mesmo módulo carregador.

> OBS: É possível retirar antes de se carregar por completo.

---

### 🤖 Como usar os códigos

Para usar o código no robô controlado por cores, basta carregá-lo pela IDE. Dependendo de seu interesse, há **2 códigos** disponíveis para uso:

1. **Código de calibração manual do sensor TCS3200 para cor**, permitindo configuração dinâmica dos valores de cada cor a depender do ambiente + controle de velocidade por PWM, disponível na branch [Calibracao-Sensor_Cor-PWM](https://github.com/IEEE-RAS/Carrinho-Controlado-Por-Cores/tree/Calibracao-Sensor_Cor-PWM);

2. **Código sem calibração manual do sensor**, usando um alcance de cada cor configurado de forma constante + controle de velocidade por PWM, disponível na branch [Calibracao-Velocidade](https://github.com/IEEE-RAS/Carrinho-Controlado-Por-Cores/tree/Calibracao-Velocidade).

Recomenda-se utilizar a **Opção 1**, pois ela permite adequação à quantidade de luz do ambiente. Porém, caso seja de interesse pular a etapa de calibração, pode-se utilizar a **Opção 2**.

#### 📌 Processo de calibração do sensor

1. A primeira etapa é encontrar o *jumper* (fio) usado para mudança de estado. Ele é um fio macho-macho, onde uma extremidade é conectada ao **GND** do WAVGAT e a outra extremidade está desconectada.

2. Ligue o robô pelo interruptor — posição **"I"**.

3. Ao ligar, o robô estará no modo de calibração, esperando mudanças na entrada **2** do WAVGAT. A cada mudança será trocada a cor que está sendo calibrada. A ordem é:

   * **1ª mudança** → calibra cor vermelha  
   * **2ª mudança** → calibra cor verde  
   * **3ª mudança** → calibra cor azul  
   * **4ª mudança** → calibra cor preta  

4. Coloque a superfície vermelha abaixo do sensor. Encoste rapidamente o *jumper* usado na entrada **2**. Se atente que um LED no WAVGAT irá piscar ao conectar. Espere até o LED piscar novamente. Após essa segunda piscada, já pode alterar a cor.

> OBS: NÃO PRECISA CONECTAR O JUMPER NA ENTRADA 2. APENAS ENCOSTAR JÁ FUNCIONA. UTILIZE O LED COMO REFERÊNCIA.

5. Troque a superfície para a cor verde. Repita o processo de encostar o *jumper* na entrada **2**.

6. Troque a superfície para a cor azul. Repita o processo de encostar o *jumper* na entrada **2**.

7. Troque a superfície para a cor preta. Repita o processo de encostar o *jumper* na entrada **2**.

8. Se tudo ocorrer corretamente, o robô já estará pronto para uso.


---

## 🚀 Como Contribuir

Somos um projeto de código e hardware abertos\! Se você deseja contribuir:

1. **Faça um Fork** deste repositório.
2. **Crie uma Branch** para sua feature (`git checkout -b feature/SuaFeature`).
3. **Faça o Commit** de suas mudanças (`git commit -m 'Adiciona SuaFeature'`).
4. **Faça o Push** para a Branch (`git push origin feature/SuaFeature`).
5. Abra um **Pull Request**.

Para problemas ou sugestões, por favor, abra uma **Issue**.
