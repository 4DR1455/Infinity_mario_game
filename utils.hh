//NOT DONE BY ME

#ifndef UTILS_HH
#define UTILS_HH

#include <vector>
#include <random>
#include "geometry.hh"
#include "window.hh"

namespace pro2 {

/**
 * @brief Dibuja una línea horizontal en la ventana.
 *
 * @param window Ventana en la que se dibuja la línea.
 * @param xini Coordenada x inicial.
 * @param xfin Coordenada x final.
 * @param y Coordenada y.
 * @param color Color de la línea (opcional, si no se pone se asume `white`).
 */
void paint_hline(pro2::Window& window, int xini, int xfin, int y, pro2::Color color = pro2::white);

/**
 * @brief Dibuja una línea vertical en la ventana.
 *
 * @param window Ventana en la que se dibuja la línea.
 * @param x Coordenada x.
 * @param yini Coordenada y inicial.
 * @param yfin Coordenada y final.
 * @param color Color de la línea (opcional, si no se pone se asume `white`).
 */
void paint_vline(pro2::Window& window, int x, int yini, int yfin, pro2::Color color = pro2::white);

void paint_rect(pro2::Window&window, int length, int high, pro2::Pt posi, pro2::Color color = pro2::red);

/**
 * @brief Retorna un valor aleatori. Métode clàssic sembrant amb la data actual amb precissió de mil·lisegons
 * @return Random value.
 * @param min El nombre mínim que pot prendre el nombre aleatori.
 * @param max El nombre màxim que pot prendre el nombre aleatori.
 * @param rd El generador de nombres aleatoris.
 */
int nombre_aleatori(int min, int max);
/**
 * @brief Dibuixa una imatge/textura a la finestra a partir d'una posició
 *
 * @param window Finestra a la que pintar
 * @param orig   Origen (cantonada de dalt a l'esquerra) del rectangle que forma el _sprite_
 * @param sprite Matriu de colors que representa la imatge (_sprite_).
 * @param mirror Si cal pintar girar la textura horitzontalment
 */
void paint_sprite(pro2::Window&                        window,
                  pro2::Pt                             orig,
                  const std::vector<std::vector<int>>& sprite,
                  bool                                 mirror);

}  // namespace pro2

#endif