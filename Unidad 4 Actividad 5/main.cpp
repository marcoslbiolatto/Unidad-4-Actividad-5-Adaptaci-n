#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

int main() {
    // Configuraci�n inicial de la ventana
    const unsigned int initialWidth = 800;
    const unsigned int initialHeight = 600;
    RenderWindow window(VideoMode(initialWidth, initialHeight), "Adaptaci�n");

    // Definir los l�mites de tama�o permitidos para la ventana
    const unsigned int minWidth = 100;
    const unsigned int minHeight = 100;
    const unsigned int maxWidth = 1000;
    const unsigned int maxHeight = 1000;

    // Bucle principal de la aplicaci�n
    while (window.isOpen()) {
        Event event;

        // Procesamiento de eventos
        while (window.pollEvent(event)) {
            // Evento de cierre de la ventana
            if (event.type == Event::Closed)
                window.close();

            // Evento de redimensionamiento de la ventana
            if (event.type == Event::Resized) {
                // Obtener el nuevo tama�o de la ventana
                unsigned int newWidth = event.size.width;
                unsigned int newHeight = event.size.height;

                // Ajustar el tama�o para que est� dentro de los l�mites
                if (newWidth < minWidth) newWidth = minWidth;
                else if (newWidth > maxWidth) newWidth = maxWidth;

                if (newHeight < minHeight) newHeight = minHeight;
                else if (newHeight > maxHeight) newHeight = maxHeight;

                // Aplicar el nuevo tama�o ajustado a la ventana
                window.setSize(Vector2u(newWidth, newHeight));
            }
        }

        // Limpiar la pantalla con un color de fondo
        window.clear(Color::Black);

        // Mostrar el contenido en pantalla
        window.display();
    }

    return 0;
}