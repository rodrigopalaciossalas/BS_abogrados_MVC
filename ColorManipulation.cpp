#include "ColorManipulation.hpp"

void resetColor() {
    std::cout << "\x1B[m"; // Resetea los colores y estilos a los predeterminados
}

void setTextColor(int colorCode) {
    std::cout << "\x1B[" << colorCode << "m"; // Establece el color de texto
}

void setBackgroundColor(int colorCode) {
    std::cout << "\x1B[" << (colorCode + 10) << "m"; // Establece el color de fondo (10 + código de color)
}

void setBold() 
{
    std::cout << "\x1B[1m"; // Aplica negrita
}

void setItalic() 
{
    std::cout << "\x1B[3m"; // Aplica cursiva
}

void setBlinking() {
    std::cout << "\x1B[5m"; // Aplica parpadeo
}

void resetCursor() {
    std::cout << "\x1B[H"; // Coloca el cursor en la parte superior izquierda
}
void clearScreen() {
    std::cout << "\x1B[2J"; // Limpia la pantalla
}