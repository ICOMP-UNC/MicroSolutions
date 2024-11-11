# MicroSolutions

Descripción del proyecto:

El proyecto consiste en un sistema de auto-generación de energía eléctrica para que la placa LPC1769 sea autosusutentable generando su propia energía, mediante un sistema de seguimiento solar con un modo manual y otro automático, un panel solar, un cargador de bateráa y una batería de litio.

Objetivos Principales:

1) Inicio del sistema luego del reset en modo de seguimiento solar automático.
2) Primera orientación inicial automática del panel solar con exito.
3) Posterior seguimiento solar, buscando la mayor intensidad de radiación recibida.
4) Conmutación de modo automático a modo manual (y vice versa) mediante un pulsador.
5) Orientacion manual del panel solar mediante un módulo joystick.
6) Indicación del nivel de batería mediante la variación de frecuencia de parpadeo de un led.

 Criterios de éxito:

 El sistema se considerará exitoso si se puede asegurar que la placa LPC1769 puede autosusentarse con el mismo.

Cronograma de 5 Días:

Día 1: Planificación Rápida y Estructura del Repositorio

Descripción del Proyecto:
Redactar un párrafo breve en el README.md explicando el propósito general del sistema embebido y los objetivos clave.

Definir Objetivos y Hitos:
Esbozar una lista breve de los objetivos y criterios de éxito en el README.md.

Estructura del Repositorio y Ramas:
Crear ramas para cada módulo principal a desarrollar.
Establecer una rama de lanzamiento 1.0.0 para la versión final, a la cual no se hará commits directos.

Día 2: Documentación de Diseño y Preparación del Código Base

Diagramas y Arquitectura del Sistema:
Crear diagramas de bloques y de flujo que describan la arquitectura general. Cargarlos en el repositorio y enlazarlos en el Wiki.

Documentación de Módulos:
En el Wiki, describir brevemente cada módulo principal y cómo interactúan entre sí.

Configuración de CI/CD:
Configurar una simple GitHub Action para compilar el código al hacer pull requests en las ramas de desarrollo.

Día 3: Desarrollo de Código Base y Estilo

Implementación de Código Modular:
Implementar las funciones base en cada módulo, con código modular y documentado.
Aplicar clang-format para asegurar consistencia en el estilo de código.

Documentación con Doxygen:
Agregar comentarios al estilo Doxygen en el código para cada función y módulo clave. Documentación breve y clara.

Pruebas Básicas:
Hacer pruebas rápidas de las funciones para verificar que cada módulo cumple con su propósito.

Día 4: Documentación Final y Ensamble del Proyecto

INSTALL.md:
Escribir instrucciones claras sobre cómo compilar e instalar el firmware en la placa.
Incluír detalles de herramientas específicas, como CMSIS o OpenOCD, que sean necesarias para programar la LPC1769.

Especificaciones de Hardware:
Agrega una descripción de los componentes de hardware en el README.md, mediante un diagramas de esquema y una guía básica para conectar sensores o actuadores.

Generación de Documentación HTML con Doxygen:
Usar Doxygen para generar la documentación HTML y colocarla en un directorio docs/ dentro del repositorio.

Día 5: Revisión, Ajustes Finales y Preparación para la Entrega

Revisión de Código y Documentación:
Revisar el código para asegurar que todos los comentarios y la documentación estén completos y sean claros.

Limpieza y Confirmación del Repositorio:
Asegurar de que el README.md, INSTALL.md, y otros archivos estén actualizados y claros.
Verificar que el flujo CI/CD esté funcionando sin errores.

Preparación Final del Proyecto:
Hacer una última revisión del Wiki para ver si todo está documentado y actualizado.
Realizar una última prueba de compilación y verificación de funcionamiento del prototipo.
