#ifndef HUMMER_HH
#define HUMMER_HH

#include "utils.hh"
#include <vector>

class Hummer {
    private:

        const int _ = -1;
        const int m = 0x693d00;
        const int n = pro2::black;
        const int b = pro2::white;
        const int g = pro2::yellow;

        const std::vector<std::vector<int>> sprite = {
            {_,m,m,m,m,_,_,_,_,_,_,_,_,_,_,_},
            {m,m,m,m,m,m,_,_,_,_,_,_,_,_,_,_},
            {_,g,g,g,g,_,_,_,_,_,_,_,_,_,_,_},
            {_,m,m,m,m,_,_,_,_,_,_,_,_,_,_,_},
            {_,m,m,m,m,n,_,_,_,_,_,_,_,_,m,_},
            {_,m,m,m,m,n,m,m,m,m,m,m,m,g,m,g},
            {_,m,m,m,m,n,m,m,m,m,m,m,m,g,m,g},
            {_,m,m,m,m,n,_,_,_,_,_,_,_,_,m,_},
            {_,m,m,m,m,_,_,_,_,_,_,_,_,_,_,_},
            {_,g,g,g,g,_,_,_,_,_,_,_,_,_,_,_},
            {m,m,m,m,m,m,_,_,_,_,_,_,_,_,_,_},
            {_,m,m,m,m,_,_,_,_,_,_,_,_,_,_,_},
        };

        pro2::Rect a_rect_; //Hummer's hitbox.

        pro2::Rect s_rect_; //Hummer's activation hitbox.

        bool attacking_;

        pro2::Pt posi_;



    public:

        Hummer(pro2::Pt posi) : posi_(posi), a_rect_({posi.x, posi.y, posi.x + 15, posi.y+33}), s_rect_({a_rect_.left, a_rect_.top, a_rect_.right, a_rect_.top + 11}), attacking_(false) {}

        /**
         * @brief Hummer.attack() activates Hummer's attack mode.
         */
        void attack() {attacking_ = true;}

        /**
         * @brief Hummer.colliding() returns if @a rect1 and @a rect2 collide.
         * @pre 2 Rect.
         * @post A boolean.
         * @param rect1 First Rect.
         * @param rect2 Second Rect.
         */
        bool colliding(const pro2::Rect qrect) {
            bool vertical = (s_rect_.top <= qrect.bottom && s_rect_.bottom >= qrect.top);
            bool horizontal = (s_rect_.right >= qrect.left && s_rect_.left <= qrect.right);
            return vertical && horizontal;
        }

        /**
         * @brief Document.update() executes the next step of Hummer's attacking pattern if it is in attack mode.
         * */
        void update() {
            if (attacking_) {
                posi_ = {posi_.x, posi_.y + 2};
                a_rect_ = {posi_.x, posi_.y, posi_.x + 15, posi_.y+33};
                s_rect_ = {a_rect_.left, a_rect_.top, a_rect_.right, a_rect_.top + 11};
            }
        }

        /**
         * @brief Hummer.paint() paints the hummer.
         * @param window The window where the Hummer has to be painted.
         */
        void paint(pro2::Window& window) {
            pro2::paint_sprite(window, posi_, sprite, false);
        }

        /**
         * @brief Hummer.get_rect() returns the Hummer's hitbox.
         */
        pro2::Rect get_rect() {return a_rect_;}

        /**
         * @brief Hummer.get_rect() returns the Hummer's activation hitbox.
         */
        pro2::Rect h_rect() {return {a_rect_.left, a_rect_.top, a_rect_.right, a_rect_.top + 11};}
};

#endif
