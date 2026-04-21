# Taller de Direccionamiento de Memoria en C++

## Requisitos

Antes de ejecutar el proyecto, asegúrate de tener instalado:

* Docker

Puedes verificarlo con:

```bash
docker --version
```

## Estructura del proyecto

```
.
├── Actividad 1.cpp
├── Actividad 2.cpp
├── Actividad 3.cpp
├── Actividad 4.cpp
├── extra.cpp
├── Dockerfile
└── README.md
```

## Construcción de la imagen

Ubícate en la carpeta del proyecto y ejecuta:

```bash
docker build -t tarea .
```

Esto creará una imagen llamada `tarea` basada en GCC y compilará todos los programas.


## Ejecución del contenedor

Para ejecutar el proyecto:

```bash
docker run tarea
```

Esto ejecutará automáticamente todas las actividades en el siguiente orden:

1. Actividad 1
2. Actividad 2
3. Actividad 3
4. Actividad 4
5. Extra

## Notas importantes

* Cada archivo `.cpp` contiene su propia función `main`, por lo que se compilan por separado.
* Se utiliza `bash -c` en el Dockerfile para ejecutar múltiples programas en secuencia.
* Si uno de los programas falla, los siguientes no se ejecutarán.


## Presentado por

- Jose Harvey Barrera Ramos
- Isabela Gutiérrez Reyes
- Isabella Pacheco Marin