# 🎮 so_long

**so_long** es un proyecto gráfico de la escuela 42 cuyo objetivo es crear un pequeño juego en 2D usando la biblioteca gráfica **MiniLibX**. El jugador debe moverse por un mapa, recolectar todos los objetos y llegar a la salida, evitando enemigos (opcional, para bonus).

---

## 📌 Objetivo del proyecto

Implementar un juego simple donde:

- El jugador se mueve en una cuadrícula (mapa 2D).
- Debe recoger todos los coleccionables (`C`) y luego alcanzar la salida (`E`).
- Los muros (`1`) son obstáculos, los espacios vacíos (`0`) se pueden pisar.
- La posición inicial del jugador es marcada con una `P`.

El juego se cierra automáticamente cuando el jugador alcanza la salida con todos los coleccionables.

---

🛠️ Compilación

Este proyecto requiere la biblioteca MiniLibX, incluida o instalada en el sistema.

make

Esto generará un ejecutable llamado so_long.
🕹️ Cómo jugar

./so_long maps/map1.ber

Controles
Tecla	Acción
W o ↑	Mover arriba
A o ←	Mover izquierda
S o ↓	Mover abajo
D o →	Mover derecha
ESC	Cerrar el juego
🧾 Formato del mapa

Los mapas deben tener extensión .ber y seguir estas reglas:

    Rectangular (todas las líneas deben tener la misma longitud).

    Rodeado completamente de muros (1).

    Debe contener al menos:

        1 jugador (P)

        1 salida (E)

        1 coleccionable (C)

    Sólo se permiten los caracteres: 0, 1, C, E, P

Ejemplo válido:

111111
1P0C01
100001
1C0E11
111111

🔍 Validación del mapa

Antes de empezar el juego, el mapa es validado para asegurar:

    Que sea rectangular.

    Que esté cerrado por muros.

    Que contenga los elementos necesarios.

    Que no haya caracteres inválidos.


🎯 Objetivos principales

    Crear una ventana con MiniLibX.

    Dibujar sprites para cada celda del mapa.

    Responder a eventos del teclado.

    Controlar el movimiento del jugador y su interacción con el entorno.

    Contar y mostrar los pasos realizados.

🚫 Errores y gestión

El programa debe manejar errores con mensajes claros, por ejemplo:

    "Error: Mapa no rectangular"

    "Error: Archivo no válido"

    "Error: No se puede abrir el archivo"

Además, se debe liberar toda la memoria usada antes de salir.

🧠 Aprendizajes clave

    Uso de gráficos con MiniLibX.

    Manejo de eventos (teclado, cierre de ventana).

    Gestión de memoria y estructuras dinámicas.

    Validación robusta de entradas.

    Algoritmos de recorrido de grafos para validar mapas.

