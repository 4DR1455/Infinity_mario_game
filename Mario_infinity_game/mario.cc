//I JUST DID THE PAINT FUNCTION, THE ANIMATION, AND DESIGNED RUNNING SPRITES.

#include "mario.hh"
#include "utils.hh"

const int _ = -1;
const int r = pro2::red;
const int s = 0xecc49b;
const int b = 0x5e6ddc;
const int y = pro2::yellow;
const int h = pro2::black;
const int g = 0xaaaaaa;
const int w = 0x8d573c;

// clang-format off
const std::vector<std::vector<int>> Mario::mario_sprite_normal_ = { //hitbox = 12x16  (wxh)
    {_, _, _, r, r, r, r, r, _, _, _, _},
    {_, _, r, r, r, r, r, r, r, r, r, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, r, r, b, r, r, r, _, _, _, _},
    {_, r, r, r, b, r, r, b, r, r, r, _},
    {r, r, r, r, b, b, b, b, r, r, r, r},
    {g, g, r, b, y, b, b, y, b, r, g, g},
    {g, g, g, b, b, b, b, b, b, g, g, g},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, w, w, w, _, _, _, _, w, w, w, _},
    {w, w, w, w, _, _, _, _, w, w, w, w},
};

const std::vector<std::vector<int>> Mario::mario_sprite_runing_0_ = { //hitbox = 12x16  (wxh)
    {_, _, _, r, r, r, r, r, _, _, _, _},
    {_, _, r, r, r, r, r, r, r, r, r, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, r, r, b, r, r, r, _, _, _, g},
    {_, r, r, r, b, r, r, b, r, r, g, g},
    {_, r, r, r, b, b, b, b, r, r, g, g},
    {_, _, g, b, y, b, b, y, b, r, g, _},
    {_, _, _, b, b, b, b, b, b, _, _, _},
    {_, _, b, b, b, b, b, b, b, b, _, _},
    {_, w, w, w, _, _, _, b, b, b, _, _},
    {_, w, w, w, w, _, _, w, w, w, _, _},
    {_, _, _, _, _, _, _, w, w, w, w, _},
};

const std::vector<std::vector<int>> Mario::mario_sprite_runing_1_ = { //hitbox = 12x16  (wxh)
    {_, _, _, r, r, r, r, r, _, _, _, _},
    {_, _, r, r, r, r, r, r, r, r, r, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, r, r, b, r, r, r, _, _, _, _},
    {_, _, r, r, b, r, r, b, r, g, g, _},
    {_, _, r, r, b, b, b, b, r, g, g, _},
    {_, _, w, w, y, b, b, y, b, g, g, _},
    {_, _, w, w, b, b, b, b, b, _, _, _},
    {_, _, w, w, b, b, b, b, b, b, _, _},
    {_, _, w, w, b, b, b, b, _, _, _, _},
    {_, _, w, _, _, _, w, w, w, _, _, _},
    {_, _, _, _, _, _, w, w, w, w, _, _},
};

const std::vector<std::vector<int>> Mario::mario_sprite_runing_2_ = { //hitbox = 12x16  (wxh)
    {_, _, _, r, r, r, r, r, _, _, _, _},
    {_, _, r, r, r, r, r, r, r, r, r, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, r, r, b, r, r, r, _, _, _, _},
    {_, _, r, r, b, r, r, r, g, _, _, _},
    {_, _, r, r, b, b, b, r, g, g, _, _},
    {_, _, _, w, y, b, b, r, g, _, _, _},
    {_, _, _, w, w, b, b, b, _, _, _, _},
    {_, _, _, w, w, b, b, b, _, _, _, _},
    {_, _, _, w, w, b, b, _, _, _, _, _},
    {_, _, _, w, w, w, w, _, _, _, _, _},
    {_, _, _, _, w, w, w, w, _, _, _, _},
};

const std::vector<std::vector<int>> Mario::mario_sprite_runing_3_ = { //hitbox = 12x16  (wxh)
    {_, _, _, r, r, r, r, r, _, _, _, _},
    {_, _, r, r, r, r, r, r, r, r, r, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, r, r, b, r, r, r, _, _, _, _},
    {_, _, r, r, g, r, r, b, r, g, _, _},
    {_, _, r, r, g, g, b, b, r, g, _, _},
    {_, _, _, g, g, g, b, y, b, g, _, _},
    {_, _, _, b, g, b, b, b, b, _, _, _},
    {_, _, _, b, b, b, w, w, w, b, _, _},
    {_, _, _, b, b, b, w, w, w, w, _, _},
    {_, _, w, w, w, _, _, _, _, _, _, _},
    {_, _, w, w, w, w, _, _, _, _, _, _},
};

const std::vector<std::vector<int>> Mario::mario_sprite_runing_4_ = { //hitbox = 12x16  (wxh)
        {_, _, _, r, r, r, r, r, _, _, _, _},
    {_, _, r, r, r, r, r, r, r, r, r, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, r, r, b, r, r, r, _, _, g, _},
    {_, r, r, r, b, r, r, b, r, g, g, _},
    {_, r, r, r, g, b, b, b, r, g, g, _},
    {_, _, g, g, g, g, b, y, b, g, _, _},
    {_, _, _, g, g, b, b, b, b, _, _, _},
    {_, _, b, b, b, b, b, b, b, b, _, _},
    {_, b, b, b, _, _, _, w, w, w, _, _},
    {_, w, w, w, _, _, _, w, w, w, w, _},
    {_, w, w, w, w, _, _, _, _, _, _, _},
};
// clang-format on

void Mario::paint(pro2::Window& window) {
    const pro2::Pt top_left = {pos_.x - 6, pos_.y - 15};
    if (runing_) {
        switch (k_)
        {
        case 0:
            paint_sprite(window, top_left, mario_sprite_runing_0_, looking_left_);
            if (grounded_) k_++;
            runing_ = false;
            break;
        case 1:
            paint_sprite(window, top_left, mario_sprite_runing_1_, looking_left_);
            if (grounded_) k_++;
            runing_ = false;
            break;
        case 2:
            paint_sprite(window, top_left, mario_sprite_runing_2_, looking_left_);
            if (grounded_) k_++;
            runing_ = false;
            break;
        case 3:
            paint_sprite(window, top_left, mario_sprite_runing_3_, looking_left_);
            if (grounded_) k_++;
            runing_ = false;
            break;
        case 4:
            paint_sprite(window, top_left, mario_sprite_runing_4_, looking_left_);
            if (grounded_) k_ = 0;
            runing_ = false;
            break;
        
        default:
            break;
        }
    }
    
    else paint_sprite(window, top_left, mario_sprite_normal_, looking_left_);
}

void Mario::apply_physics_() {
    if (grounded_) {
        speed_.y = 0;
        accel_.y = 0;
    }

    // Always falling to check if we aren't grounded
    // If we are, we will return to the same spot

    const int gravity = 1;  // gravity = 1 pixel / frame_time^2
    speed_.y += gravity;

    if (accel_time_ > 0) {
        speed_.y += accel_.y;
        accel_time_--;
    }

    pos_.x += speed_.x;
    pos_.y += speed_.y;
}

void Mario::jump() {
    if (grounded_) {
        accel_.y = -6;
        grounded_ = false;
        accel_time_ = 2;
    }
}

void Mario::update(pro2::Window& window, const std::list<Platform>& platforms) {
    last_pos_ = pos_;
    if (window.is_key_down(jump_key_)) {
        jump();
    }

    // Velocitat horitzontal
    speed_.x = 0; 
    if (window.is_key_down(left_key_)) {
        speed_.x = -4;
    } else if (window.is_key_down(right_key_)) {
        speed_.x = 4;
    }
    if (speed_.x != 0) {
        looking_left_ = speed_.x < 0;
        runing_ = true;
    }

    rect_ = {pos_.x - 6, pos_.y - 15, pos_.x + 5, pos_.y};

    // Apply acceleration and speed
    apply_physics_();

    // Check position
    set_grounded(false);

    for (const Platform& platform : platforms) {
        if (platform.has_crossed_floor_downwards(last_pos_, pos_)) {
            set_grounded(true);
            set_y(platform.top());
        }
    }
}
