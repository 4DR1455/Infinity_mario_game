#include "utils.hh"
#include <iostream>
using namespace std;

namespace pro2 {

void paint_hline(pro2::Window& window, int xini, int xfin, int y, Color color) {
    for (int x = xini; x <= xfin; x++) {
        window.set_pixel({x, y}, color);
    }
}

void paint_vline(pro2::Window& window, int x, int yini, int yfin, Color color) {
    for (int y = yini; y <= yfin; y++) {
        window.set_pixel({x, y}, color);
    }
}

void paint_rect(pro2::Window&window, int length, int high, pro2::Pt posi, pro2::Color color) {
    int fiy = high + posi.y;
    int fix = length + posi.x;
    for (int y = posi.y; y < fiy ; y++) {
        for (int x = posi.x; x < fix; x++) {
            window.set_pixel({x,y}, color);
        }
    }
}

int nombre_aleatori(int min, int max) {
    std::random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(min, max);
    return int(dist(gen));
}

void paint_sprite(pro2::Window&              window,
                  pro2::Pt                   orig,
                  const vector<vector<int>>& sprite,
                  bool                       mirror) {
    for (int i = 0; i < sprite.size(); i++) {
        const vector<int>& line = sprite[i];
        for (int j = 0; j < line.size(); j++) {
            const int _j = mirror ? line.size() - j - 1 : j;
            if (line[_j] >= 0) {
                window.set_pixel({orig.x + j, orig.y + i}, line[_j]);
            }
        }
    }
}

}  // namespace pro2