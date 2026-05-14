# Taller de Direccionamiento de Memoria en C++

## Requisitos

Antes de ejecutar el proyecto, asegúrate de tener instalado:

* Docker

Puedes verificarlo con:

```bash
docker --version
```

---

## Estructura del proyecto

```
memoryAddressing/
├── Parte 1/
│   ├── Actividad 1.cpp
│   ├── Actividad 2.cpp
│   ├── Actividad 3.cpp
│   ├── Actividad 4.cpp
│   ├── extra.cpp
│   ├── Dockerfile
│   └── INFORME TAREA 3.pdf
│
└── Parte 2/
    ├── Disk scheduling.cpp
    ├── Disk scheduling.h
    ├── main.cpp
    ├── report.cpp
    ├── report.h
    ├── index.html
    ├── entrypoint.sh
    └── Dockerfile
```

---

## Parte 1 — Actividades de memoria

Compila y ejecuta cuatro actividades de direccionamiento de memoria en secuencia.

### Construcción

Ubícate en la carpeta `Parte 1` y ejecuta:

```bash
cd "Parte 1"
docker build -t uno .
```

### Ejecución

```bash
docker run uno
```

La salida de las cuatro actividades aparece directamente en la consola en el siguiente orden:

1. Actividad 1
2. Actividad 2
3. Actividad 3
4. Actividad 4
5. Extra

---

## Parte 2 — Disk Scheduling

Simula los algoritmos de agendamiento de disco **FCFS**, **SCAN** y **C-SCAN** y genera una visualización interactiva con gráficas comparativas accesible desde el navegador.

### Construcción

Ubícate en la carpeta `Parte 2` y ejecuta:

```bash
cd "Parte 2"
docker build -t dos .
```

### Ejecución

```bash
docker run -e HEAD=2500 -p 8080:8080 dos
```

Luego abre en el navegador:

```
http://localhost:8080/index.html
```

### Parámetros

| Parámetro | Descripción | Valor por defecto |
|-----------|-------------|-------------------|
| `HEAD` | Posición inicial de la cabeza del disco (0–4999) | `2500` |

Ejemplos con distintas posiciones de cabeza:

```bash
docker run -e HEAD=750  -p 8080:8080 parte2
docker run -e HEAD=4200 -p 8080:8080 parte2
```

### Importante

En caso de que el puerto 8080 ya este siendo usado se tienen 3 opciones:

1. Usar otro puerto

```bash
docker run -e HEAD=2500 -p 9090:8080 dos
```

2. Detener el contenedor que ocupa el puerto

```bash
docker ps
docker stop 'idContenedor'
docker run -e HEAD=2500 -p 8080:8080 dos
```

3. Detener todos los contenedores activos

```bash
docker stop $(docker ps -q)
docker run -e HEAD=2500 -p 8080:8080 dos
```

### Visualización

La página muestra cuatro gráficas:

- **Movimiento de la cabeza** — posición del cabezal en cada paso
- **Movimiento acumulado** — cilindros recorridos acumulados por algoritmo
- **Comparación de rendimiento** — total y promedio por solicitud
- **Responsividad del sistema** — salto máximo de cada algoritmo

### Resultados esperados

Con 1000 solicitudes aleatorias los valores típicos son:

| Algoritmo | Total (cilindros) | Promedio |
|-----------|-------------------|----------|
| FCFS      | ~1,600,000        | ~1,600   |
| SCAN      | ~7,500            | ~7.5     |
| C-SCAN    | ~10,000           | ~10.0    |

> Los valores varían en cada ejecución porque las solicitudes se generan aleatoriamente.

---

## Notas importantes

* Cada parte se construye y ejecuta de forma **independiente**.
* Cada archivo `.cpp` de la Parte 1 contiene su propia función `main` y se compila por separado.

---

## Presentado por

- Jose Harvey Barrera Ramos
- Isabela Gutiérrez Reyes
- Isabella Pacheco Marin