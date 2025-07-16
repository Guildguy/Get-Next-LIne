Descrição: O Get Next Line é um projeto que desafia a escrever uma função em C capaz de ler e retornar uma linha completa de um file descriptor (que pode ser um arquivo, entrada padrão, etc.), uma por vez, mesmo que a linha não caiba em um único buffer de leitura.

Desafios e Implementação:

Persistência de Dados: O principal desafio foi gerenciar dados de leituras parciais que excediam o tamanho do buffer. Isso foi resolvido de forma elegante utilizando variáveis estáticas para manter o estado entre as chamadas da função.

Manipulação de File Descriptors: Gerenciar a leitura de diferentes file descriptors simultaneamente (parte bônus, embora eu tenha focado na mandatório) exigiu lógica cuidadosa.

Otimização de Leitura: Balancear o tamanho do buffer para otimizar o desempenho de leitura.

O que aprendi:

Variáveis Estáticas: Compreensão aprofundada do uso e comportamento das variáveis estáticas em C.

Entrada/Saída (I/O) em C: Manipulação de file descriptors e o processo de leitura de dados de diferentes fontes.

Gerenciamento de Buffers: Estratégias para armazenar e processar dados em partes.

