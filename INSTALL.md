# 🛠️ Guía de instalación

Esta guía le ayudará a configurar las herramientas necesarias para compilar y depurar el proyecto en microcontroladores LPC1769.

## 1. Instalar ARM GCC Toolchain

LA ARM GCC Toolchain es necesaria para compilar código para microcontroladores basados en ARM.

### Linux (Debian)

```bash
sudo apt update
sudo apt install gcc-arm-none-eabi
```

### Windows

1. Descargue la cadena de herramientas ARM GCC de [ARM Developer](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm).
2. Siga las instrucciones de instalación proporcionadas en el sitio web.

## 2. Instale OpenOCD (para depuración)

OpenOCD es una herramienta de código abierto que proporciona depuración, programación en el sistema y pruebas de escaneo de límites.

### Linux

```bash
sudo apt install openocd
```

### Windows

1. Descarga OpenOCD desde el [official website](http://openocd.org/).
2. Siga las instrucciones de instalación proporcionadas en el sitio web.

## 3. Instala un IDE o editor de texto compatible

Puede utilizar varios IDE o editores de texto, pero se recomienda lo siguiente:

- **VSCode**: Un editor de código ligero con excelente soporte para el desarrollo embebido.
- **MCUExpresso** (NXP-specific): Un IDE especializado para microcontroladores NXP, recomendado para el desarrollo LPC1769. development.

### VSCode

1. Descargue e instale [VSCode](https://code.visualstudio.com/).
2. Instale las siguientes extensiones:
   - C/C++ (Microsoft)
   - Search for official [PlatformIO IDE extension](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)
     - Install PlatformIO IDE.

### MCUExpresso

1. Descargue e instale [MCUExpresso IDE](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/mcuxpresso-integrated-development-environment-ide:MCUXpresso-IDE) fdesde el sitio web de NXP.
2. Siga las instrucciones de configuración proporcionadas por NXP.

## 4. Instale Make o CMake

En función de sus preferencias de compilación, instale Make o CMake:

### Make (Linux)

```bash
sudo apt install build-essential  # For Linux
```

### Make (Windows)

1. Instale [MinGW](http://www.mingw.org/) y asegúrese de que `make` esté incluído.

### CMake

#### Linux

```bash
sudo apt install cmake
```

#### Windows

1. Descarga e instala CMake desde el [official website](https://cmake.org/download/).

## 5. Herramientas de flasheo

Para actualizar el firmware del micocontrolador necesitará OpenOCD:

- **OpenOCD**

Explicado en el paso 2.

## 6. Consideraciones adicionales

For LPC1769 projects:

- Si utiliza MCUExpresso, debe copiar los archivos de origen y los archivos de encabezado de los directorios `src` and `include` a su proyecto, excepto `newlib_stubs.c`.