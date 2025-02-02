# Cub3D 🎮

## Descripción 📜
**Cub3D** es un proyecto 2D/3D de programación de un motor gráfico estilo "raycasting".
El objetivo del proyecto es crear un juego o visualización en 3D utilizando la técnica de raycasting para renderizar paredes y otros elementos en un entorno en 3D, basándose en un mapa de texto simple.
El jugador puede moverse por el mapa, y el sistema de raycasting genera el entorno visual en función de la posición y orientación del jugador.

## Objetivo 🎯
El objetivo principal de **Cub3D** es implementar un motor gráfico utilizando la técnica de raycasting. En este proyecto se aprende a trabajar con gráficos 2D y 3D, a manejar eventos y controles del jugador, y a entender el renderizado de gráficos en tiempo real. A lo largo del proyecto, se trabaja con:

- Manipulación de mapas de texto para crear escenarios.
- Técnicas de raycasting para simular una vista en 3D.
- Manejo de controles del jugador (movimiento y rotación).
- Implementación de un motor gráfico básico en C utilizando la librería **MinilibX**.

## Características ⚙️
- **Mapa de texto**: El mapa es una representación del escenario en un archivo de texto donde cada carácter representa un tipo de pared o espacio vacío.
- **Movimiento del jugador**: El jugador puede moverse a través del escenario con las teclas de dirección y rotar con las teclas correspondientes.
- **Raycasting**: La técnica de raycasting permite proyectar rayos desde la posición del jugador hacia las paredes del mapa, generando una visualización en 3D de la escena.
- **Renderizado básico**: Generación de una vista 3D utilizando los rayos lanzados y los objetos visibles en el mapa.

## Tecnologías 💻
- **Lenguaje**: C
- **Librerías**: MinilibX (para gráficos), X11 (para la interacción con el sistema gráfico en Linux).

## Instalación ⚒️

Primero compila el proyecto:
    ```bash
    make
    ```

4. **Ejecuta el programa**:
    ```bash
    ./cub3d maps/map.cub
    ```

   - El archivo `mapa.cub` es el archivo de texto que contiene el mapa del juego.

## Uso 🚀

Al ejecutar el juego, verás una ventana donde se simula un entorno 3D básico. Puedes usar las siguientes teclas para interactuar con el juego:

- **W**: Mover hacia adelante.
- **S**: Mover hacia atrás.
- **A**: Girar hacia la izquierda.
- **D**: Girar hacia la derecha.
- **Esc**: Salir del juego.

También puedes añadir la imagen que quieras en la carpeta `/sprites` en formato tu_imagen.xpm y en el mapa que quieras añadir la dirección en cualquier textura y, a ejecutarlo, la verás en el juego.
