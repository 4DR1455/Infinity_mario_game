//I JUST DID THE PAINT FUNCTION, THE ANIMATION

#ifndef MARIO_HH
#define MARIO_HH

#include <iostream>
#include <list>
#include <list>
#include "platform.hh"
#include "window.hh"

class Platform;

class Mario {
 private:
    pro2::Rect rect_;
    pro2::Pt pos_, last_pos_;
    pro2::Pt speed_ = {0, 0};
    pro2::Pt accel_ = {0, 0};
    int      accel_time_ = 0;

    int docus_took_;

    int k_;

    bool runing_ = false;

    bool grounded_ = false;
	bool looking_left_ = false;

	void apply_physics_();
	
    char left_key_;
    char right_key_;
    char jump_key_;

 public:
    Mario(pro2::Pt pos, char left, char right, char jump) : pos_(pos), last_pos_(pos), rect_({pos.x, pos.y, pos.x+11, pos.y+15}), left_key_(left), right_key_(right), jump_key_(jump), docus_took_(0), k_(0), runing_(false) {}

    /**
     * @brief Mario.paint() makes the animation counter go on if Mario is running and decides which sprite to paint.
     * @param window The window where Mario has to be painted.
     */
    void paint(pro2::Window& window);

    pro2::Pt pos() const {
        return pos_;
    }

    pro2::Pt last_pos() const {
        return last_pos_;
    }

    pro2::Rect get_rect() const {
        return rect_;
    }

    void set_y(int y) {
        pos_.y = y;
    }

    bool is_grounded() const {
        return grounded_;
    }

    void set_grounded(bool grounded) {
        grounded_ = grounded;
        if (grounded_) {
            speed_.y = 0;
        }
    }

    void toggle_grounded() {
        set_grounded(!grounded_);
    }

    void jump();

    void update(pro2::Window& window, const std::list<Platform>& platforms);

 private:
    static const std::vector<std::vector<int>> mario_sprite_normal_;
    static const std::vector<std::vector<int>> mario_sprite_runing_0_;
    static const std::vector<std::vector<int>> mario_sprite_runing_1_;
    static const std::vector<std::vector<int>> mario_sprite_runing_2_;
    static const std::vector<std::vector<int>> mario_sprite_runing_3_;
    static const std::vector<std::vector<int>> mario_sprite_runing_4_;
};

#endif
