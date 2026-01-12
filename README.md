# STE - SeToElf Binary Loader

```
  ____ _____ _____ 
 / ___|_   _| ____|
 \___ \ | | |  _|  
  ___) || | | |___ 
 |____/ |_| |_____|
 [ SeToElf Binary Loader ]

```

**SeToElf (STE)** é uma ferramenta de baixo nível desenvolvida para transpilagem e carregamento de binários Windows (DLL) em ambiente Linux/Termux, utilizando mapeamento de memória dinâmica (RWX) e técnica de *header swapping* em tempo de execução.

## 🚀 Funcionalidades

* **Header Hijacking:** Localiza assinaturas PE (MZ) e mascara como ELF em memória RAM.
* **Memory Mapping:** Alocação de memória com permissões de leitura, escrita e execução (`mmap`).
* **Integrated Packager:** Sistema de compressão nativa para distribuição de módulos.
* **Smart Makefile:** Instalação automatizada com detecção de ambiente (Termux vs Linux Global).

## 🛠️ Instalação

Para compilar e instalar o STE globalmente no seu sistema:

```bash
git clone https://github.com/MurilooPr/SeToElf
cd SeToElf
make
make install

```

## 📖 Como Usar

Uma vez instalado, o comando `STE` estará disponível em qualquer diretório.

### Executar ou Mapear uma DLL:

```bash
STE -exc biblioteca.dll

```

### Empacotar arquivos para distribuição:

```bash
STE --pack biblioteca.dll

```

## 📂 Estrutura do Projeto

* `src/`: Código fonte da lógica do loader e packager.
* `include/`: Cabeçalhos e estruturas de dados PE/ELF.
* `bin/`: Binário final compilado (gerado pelo Makefile).

---

**Desenvolvido por MurilooPr**