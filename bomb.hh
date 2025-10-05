#ifndef BOMB_HH
#define BOMB_HH

#include "utils.hh"
#include <vector>

class Bomb {
    private:

        pro2::Pt posi_;

        const pro2::Rect rect_;

        int k_;

        int clk_;

        const int PERIOD_;

        const int n = pro2::black;
        const int g1 = 474400;
        const int g2 = 0x7a7400;
        const int g3 = 0xccc200;
        const int b = pro2::white;
        const int m = 0x331800;
        const int v = pro2::red;
        const int g = pro2::yellow;
        const int _ = -1;
        const std::vector<std::vector<int>> sprite_0 {
            {g,_,g,_,g,_,_,_,_,_,_,_,_},
            {_,g,v,g,_,_,_,_,_,_,_,_,_},
            {g,v,v,v,g,_,_,_,_,_,_,_,_},
            {_,g,v,g,m,m,_,_,_,_,_,_,_},
            {g,_,g,_,g,m,m,_,_,_,_,_,_},
            {_,_,_,_,_,_,m,_,_,_,_,_,_},
            {_,_,_,_,_,_,m,_,_,_,_,_,_},
            {_,_,_,_,_,g3,g2,n,_,_,_,_,_},
            {_,_,_,_,_,g3,g2,n,_,_,_,_,_},
            {_,_,_,g,g,g3,g1,n,n,n,_,_,_},
            {_,_,g3,g3,g3,g2,g1,n,n,n,n,_,_},
            {_,g2,g2,g2,g2,g1,n,n,n,n,n,n,_},
            {_,g1,g1,g1,g1,n,n,n,n,n,n,n,_},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,_,n,n,n,n,n,n,n,n,n,_,_},
            {_,_,_,_,n,n,n,n,n,_,_,_,_}
        };

        const std::vector<std::vector<int>> sprite_1 {
            {_,g,_,g,_,g,_,_,_,_,_,_},
            {_,_,g,v,g,_,_,_,_,_,_,_},
            {_,g,v,v,v,g,_,_,_,_,_,_},
            {_,_,g,v,g,m,_,_,_,_,_,_},
            {_,g,_,g,_,g,m,_,_,_,_,_},
            {_,_,_,_,_,_,m,_,_,_,_,_},
            {_,_,_,_,_,_,m,_,_,_,_,_},
            {_,_,_,_,_,g,g2,n,_,_,_,_,_},
            {_,_,_,_,_,g,g2,n,_,_,_,_,_},
            {_,_,_,g,g,g3,g1,n,n,n,_,_,_},
            {_,_,g3,g3,g3,g2,g1,n,n,n,n,_,_},
            {_,g2,g2,g2,g2,g1,n,n,n,n,n,n,_},
            {_,g1,g1,g1,g1,n,n,n,n,n,n,n,_},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,_,n,n,n,n,n,n,n,n,n,_,_},
            {_,_,_,_,n,n,n,n,n,_,_,_,_}
        };

        const std::vector<std::vector<int>> sprite_2 {
            {_,_,_,_,_,_,_,_,_,_,_,_},
            {_,g,_,g,_,g,_,_,_,_,_,_},
            {_,_,g,v,g,_,_,_,_,_,_,_},
            {_,g,v,v,v,g,_,_,_,_,_,_},
            {_,_,g,v,g,m,m,_,_,_,_,_},
            {_,g,_,g,_,g,m,_,_,_,_,_},
            {_,_,_,_,_,_,m,_,_,_,_,_},
            {_,_,_,_,_,g,g2,n,_,_,_,_,_},
            {_,_,_,_,_,g,g2,n,_,_,_,_,_},
            {_,_,_,g,g,g3,g1,n,n,n,_,_,_},
            {_,_,g3,g3,g3,g2,g1,n,n,n,n,_,_},
            {_,g2,g2,g2,g2,g1,n,n,n,n,n,n,_},
            {_,g1,g1,g1,g1,n,n,n,n,n,n,n,_},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,_,n,n,n,n,n,n,n,n,n,_,_},
            {_,_,_,_,n,n,n,n,n,_,_,_,_}
        };

        const std::vector<std::vector<int>> sprite_3 {
            {_,_,_,_,_,_,_,_,_,_,_,_},
            {_,_,g,_,g,_,g,_,_,_,_,_},
            {_,_,_,g,v,g,_,_,_,_,_,_},
            {_,_,g,v,v,v,g,_,_,_,_,_},
            {_,_,_,g,v,g,m,_,_,_,_,_},
            {_,_,g,_,g,_,g,_,_,_,_,_},
            {_,_,_,_,_,_,m,_,_,_,_,_},
            {_,_,_,_,_,g,g2,n,_,_,_,_,_},
            {_,_,_,_,_,g,g2,n,_,_,_,_,_},
            {_,_,_,g,g,g3,g1,n,n,n,_,_,_},
            {_,_,g3,g3,g3,g2,g1,n,n,n,n,_,_},
            {_,g2,g2,g2,g2,g1,n,n,n,n,n,n,_},
            {_,g1,g1,g1,g1,n,n,n,n,n,n,n,_},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,_,n,n,n,n,n,n,n,n,n,_,_},
            {_,_,_,_,n,n,n,n,n,_,_,_,_}
        };

        const std::vector<std::vector<int>> sprite_4 {
            {_,_,_,_,_,_,_,_,_,_,_,_},
            {_,_,_,g,_,g,_,g,_,_,_,_},
            {_,_,_,_,g,v,g,_,_,_,_,_},
            {_,_,_,g,v,v,v,g,_,_,_,_},
            {_,_,_,_,g,v,g,_,_,_,_,_},
            {_,_,_,g,_,g,m,g,_,_,_,_},
            {_,_,_,_,_,_,m,_,_,_,_,_},
            {_,_,_,_,_,g,g2,n,_,_,_,_},
            {_,_,_,_,_,g,g2,n,_,_,_,_},
            {_,_,_,g3,g,g3,g2,g1,n,n,_,_,_},
            {_,_,g2,g2,g3,g2,g2,g1,n,n,n,_,_},
            {_,g1,g1,g1,g2,g1,n,n,n,n,n,n,_},
            {_,n,n,n,g1,n,n,n,n,n,n,n,_},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,_,n,n,n,n,n,n,n,n,n,_,_},
            {_,_,_,_,n,n,n,n,n,_,_,_,_}
        };

        const std::vector<std::vector<int>> sprite_5 {
            {_,_,_,_,_,_,_,_,_,_,_,_,_},
            {_,_,_,_,g,_,g,_,g,_,_,_,_},
            {_,_,_,_,_,g,v,g,_,_,_,_,_},
            {_,_,_,_,g,v,v,v,g,_,_,_,_},
            {_,_,_,_,_,g,v,g,_,_,_,_,_},
            {_,_,_,_,g,_,g,_,g,_,_,_,_},
            {_,_,_,_,_,_,m,_,_,_,_,_,_},
            {_,_,_,_,_,g,g,g,_,_,_,_,_},
            {_,_,_,_,_,g3,g3,g3,_,_,_,_,_},
            {_,_,_,g2,g2,g2,g2,g2,g2,g2,_,_,_},
            {_,_,g1,g1,g1,g1,g1,g1,g1,g1,g1,_,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,_,n,n,n,n,n,n,n,n,n,_,_},
            {_,_,_,_,n,n,n,n,n,_,_,_,_}
        };

        const std::vector<std::vector<int>> sprite_6 {
            {_,_,_,_,_,_,_,_,_,_,_,_,_},
            {_,_,_,_,_,_,_,_,_,_,_,_,_},
            {_,_,_,_,g,_,g,_,g,_,_,_,_},
            {_,_,_,_,_,g,v,g,_,_,_,_,_},
            {_,_,_,_,g,v,v,v,g,_,_,_,_},
            {_,_,_,_,_,g,v,g,_,_,_,_,_},
            {_,_,_,_,g,_,g,_,g,_,_,_,_},
            {_,_,_,_,_,g,g,g,_,_,_,_,_},
            {_,_,_,_,_,g3,g3,g3,_,_,_,_,_},
            {_,_,_,g2,g2,g2,g2,g2,g2,g2,_,_,_},
            {_,_,g1,g1,g1,g1,g1,g1,g1,g1,g1,_,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,_,n,n,n,n,n,n,n,n,n,_,_},
            {_,_,_,_,n,n,n,n,n,_,_,_,_}
        };

        const std::vector<std::vector<int>> sprite_7 {
            {_,_,_,_,_,_,_,_,_,_,_,_,_},
            {_,_,_,_,_,_,_,_,_,_,_,_,_},
            {_,_,_,_,_,_,_,_,_,_,_,_,_},
            {_,_,_,_,g,_,g,_,g,_,_,_,_},
            {_,_,_,_,_,g,v,g,_,_,_,_,_},
            {_,_,_,_,g,v,v,v,g,_,_,_,_},
            {_,_,_,_,_,g,v,g,_,_,_,_,_},
            {_,_,_,_,g,g,g,g,g,_,_,_,_},
            {_,_,_,_,_,g3,g3,g3,_,_,_,_,_},
            {_,_,_,g2,g2,g2,g2,g2,g2,g2,_,_,_},
            {_,_,g1,g1,g1,g1,g1,g1,g1,g1,g1,_,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,_,n,n,n,n,n,n,n,n,n,_,_},
            {_,_,_,_,n,n,n,n,n,_,_,_,_}
        };

        const std::vector<std::vector<int>> sprite_8 {
            {_,_,_,_,_,_,_,_,_,_,_,_,_},
            {_,_,_,_,_,_,_,_,_,_,_,_,_},
            {_,_,_,_,_,_,_,_,_,_,_,_,_},
            {_,_,_,_,g,_,g,_,g,_,_,_,_},
            {_,_,_,_,_,g,v,g,_,_,_,_,_},
            {_,_,_,_,g,v,v,v,g,_,_,_,_},
            {_,_,_,_,_,g,v,g,_,_,_,_,_},
            {_,_,_,_,_,g,g,g,_,_,_,_,_},
            {_,_,_,_,_,g3,g3,g3,_,_,_,_,_},
            {_,_,_,g2,g2,g2,g2,g2,g2,g2,_,_,_},
            {_,_,g1,g1,g1,g1,g1,g1,g1,g1,g1,_,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,_,n,n,n,n,n,n,n,n,n,_,_},
            {_,_,_,_,n,n,n,n,n,_,_,_,_}
        };

                const std::vector<std::vector<int>> sprite_9 {
            {_,_,_,_,_,_,_,_,_,_,_,_,_},
            {_,_,_,_,_,_,_,_,_,_,_,_,_},
            {_,_,_,_,_,_,_,_,_,_,_,_,_},
            {_,_,_,_,_,_,_,_,_,_,_,_,_},
            {_,_,_,_,g,_,g,_,g,_,_,_,_},
            {_,_,_,_,_,g,v,g,_,_,_,_,_},
            {_,_,_,_,g,v,v,v,g,_,_,_,_},
            {_,_,_,_,_,g,g,g,_,_,_,_,_},
            {_,_,_,_,_,g3,g3,g3,_,_,_,_,_},
            {_,_,_,g2,g2,g2,g2,g2,g2,g2,_,_,_},
            {_,_,g1,g1,g1,g1,g1,g1,g1,g1,g1,_,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,_,n,n,n,n,n,n,n,n,n,_,_},
            {_,_,_,_,n,n,n,n,n,_,_,_,_}
        };

                const std::vector<std::vector<int>> sprite_10 {
            {_,_,_,_,_,_,_,_,_,_,_,_,_},
            {_,_,_,_,_,_,_,_,_,_,_,_,_},
            {_,_,_,_,_,_,_,_,_,_,_,_,_},
            {_,_,_,_,_,_,_,_,_,_,_,_,_},
            {_,_,_,_,_,_,_,_,_,_,_,_,_},
            {_,_,_,_,g,_,g,_,g,_,_,_,_},
            {_,_,_,_,_,g,v,g,_,_,_,_,_},
            {_,_,_,_,_,g3,g3,g3,_,_,_,_,_},
            {_,_,_,_,_,g3,g3,g3,_,_,_,_,_},
            {_,_,_,g2,g2,g2,g2,g2,g2,g2,_,_,_},
            {_,_,g1,g1,g1,g1,g1,g1,g1,g1,g1,_,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {n,n,n,n,n,n,n,n,n,n,n,n,n},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,n,n,n,n,n,n,n,n,n,n,n,_},
            {_,_,n,n,n,n,n,n,n,n,n,_,_},
            {_,_,_,_,n,n,n,n,n,_,_,_,_}
        };

        /**
        * @brief Returns if @a rect1 and @a rect2 collide.
        * @pre 2 Rect.
        * @post A boolean.
        * @param rect1 First Rect.
        * @param rect2 Second Rect.
        */ 
        static bool colliding(const pro2::Rect rect1, const pro2::Rect rect2) {
            bool vertical = (rect1.top <= rect2.bottom && rect1.bottom >= rect2.top);
            bool horizontal = (rect1.right >= rect2.left && rect1.left <= rect2.right);
            return vertical && horizontal;
        }

    public:

    Bomb(pro2::Pt posi, int p) : posi_(posi), rect_({posi_.x, posi_.y + 8, posi_.x + 11, posi_.y + 17 }), k_(0), PERIOD_(p), clk_(0) {}

    
    pro2::Rect get_rect() {return rect_;}

    /**
     * @brief Bomb.update() continues the countdown to the explosion.
     * @pre The countdown is pending to be continued.
     * @post The countdown is updated.
     */
    void update() {
        if (clk_ == PERIOD_) {
            clk_ = 0;
            k_++;
        }
        else {
            clk_++;
        }
    }

    /**
     * @brief Bomb.pint() decides which sprite has to be used based on the countdown stage.
     * @param window The window where the Bomb has to be painted.
     */
    void paint(pro2::Window& window) {
        switch (k_)
        {
        case 0:
            pro2::paint_sprite(window, posi_, sprite_0, false); 
            break;
        case 1:
            pro2::paint_sprite(window, posi_, sprite_1, false); 
            break;
        case 2:
            pro2::paint_sprite(window, posi_, sprite_2, false); 
            break;
        case 3:
            pro2::paint_sprite(window, posi_, sprite_3, false); 
            break;
        case 4:
            pro2::paint_sprite(window, posi_, sprite_4, false); 
            break;
        case 5:
            pro2::paint_sprite(window, posi_, sprite_5, false); 
            break;
        case 6:
            pro2::paint_sprite(window, posi_, sprite_6, false); 
            break;
        case 7:
            pro2::paint_sprite(window, posi_, sprite_7, false); 
            break;
        case 8:
            pro2::paint_sprite(window, posi_, sprite_8, false); 
            break;
        case 9:
            pro2::paint_sprite(window, posi_, sprite_9, false); 
            break;
        case 10:
            pro2::paint_sprite(window, posi_, sprite_10, false); 
            break;
        
        default:
            break;
        }
    }

    /**
     * @brief Bomb.explode() returns if the countdown is at 0 && the Bomb is still on the playing space.
     * @param window The window from where we know the gaming space Rect.
     */
    bool explode(pro2::Window& window) {
        return k_ == 12 && colliding(window.camera_rect(), rect_);
    }
};

#endif