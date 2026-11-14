# Projeto Conjunto de produção de Sistema Kanban
## Estrutura do projeto

```
kanban/
├── README.md
├── Doxyfile
├── .gitignore
├── codeblocks - doxygen/
│   ├── projetotp1.cbp
│   ├── bin/
│   └── obj/
├── docs/
│   └── html/
│       └── index.html
└── src/
    ├── main.cpp
    ├── domain/
    │   ├── headers/
    │   │   ├── email.h
    │   │   ├── estado.h
    │   │   ├── identificador.h
    │   │   ├── limite.h
    │   │   ├── nome.h
    │   │   ├── papel.h
    │   │   ├── prioridade.h
    │   │   ├── senha.h
    │   │   ├── tamanho.h
    │   │   ├── texto.h
    │   │   └── timestamp.h
    │   └── sources/
    │       ├── email.cpp
    │       ├── estado.cpp
    │       ├── identificador.cpp
    │       ├── limite.cpp
    │       ├── nome.cpp
    │       ├── papel.cpp
    │       ├── prioridade.cpp
    │       ├── senha.cpp
    │       ├── tamanho.cpp
    │       ├── texto.cpp
    │       └── timestamp.cpp
    └── entities/
        ├── headers/
        │   ├── cartao_atividade.h
        │   ├── pessoa.h
        │   ├── projeto.h
        │   └── quadro.h
        └── sources/
            ├── cartao_atividade.cpp
            ├── pessoa.cpp
            ├── projeto.cpp
            └── quadro.cpp
```

### Organização por camada

| Camada | Pasta | Conteúdo |
|--------|-------|----------|
| Domínio | `src/domain/` | Tipos básicos com validação (nome, e-mail, senha, texto, identificador, estado, prioridade, papel, tamanho, limite, timestamp) |
| Entidades | `src/entities/` | Classes do negócio (pessoa, projeto, quadro, cartão de atividade) |

Cada classe tem uma pasta `headers/` (arquivos `.h`) e uma pasta `sources/` (arquivos `.cpp`).
