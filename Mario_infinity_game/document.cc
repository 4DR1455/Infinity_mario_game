#include "document.hh"
#include "utils.hh"

const int _ = -1;
const int b = pro2::white;
const int y = 0x424242;

const std::vector<std::vector<int>> Document::document_sprite_front_ = { //hitbox = 7x13  (wxh)
    { y, y, y, y, y, y, y },
    { y, y, y, y, y, y, y },
    { y, b, b, b, b, b, y },
    { y, y, y, y, y, y, y },
    { y, b, b, b, b, b, y },
    { y, y, y, y, y, y, y },
    { y, b, b, b, b, b, y },
    { y, y, y, y, y, y, y },
    { y, b, b, b, b, b, y },
    { y, y, y, y, y, y, y },
    { y, b, b, b, b, b, y },
    { y, y, y, y, y, y, y },
    { y, y, y, y, y, y, y }
};

const std::vector<std::vector<int>> Document::document_sprite_midfront_ = {
    { _, y, y, y, y, y, _ },
    { _, y, y, y, y, y, _ },
    { _, y, b, b, b, y, _ },
    { _, y, y, y, y, y, _ },
    { _, y, b, b, b, y, _ },
    { _, y, y, y, y, y, _ },
    { _, y, b, b, b, y, _ },
    { _, y, y, y, y, y, _ },
    { _, y, b, b, b, y, _ },
    { _, y, y, y, y, y, _ },
    { _, y, b, b, b, y, _ },
    { _, y, y, y, y, y, _ },
    { _, y, y, y, y, y, _ }
};

const std::vector<std::vector<int>> Document::document_sprite_midsite_ = {
    { _, _, y, y, y, _, _ },
    { _, _, y, y, y, _, _ },
    { _, _, y, b, y, _, _ },
    { _, _, y, y, y, _, _ },
    { _, _, y, b, y, _, _ },
    { _, _, y, y, y, _, _ },
    { _, _, y, b, y, _, _ },
    { _, _, y, y, y, _, _ },
    { _, _, y, b, y, _, _ },
    { _, _, y, y, y, _, _ },
    { _, _, y, b, y, _, _ },
    { _, _, y, y, y, _, _ },
    { _, _, y, y, y, _, _ }
};

const std::vector<std::vector<int>> Document::document_sprite_site_ = {
    { _, _, _, y, _, _, _ },
    { _, _, _, y, _, _, _ },
    { _, _, _, y, _, _, _ },
    { _, _, _, y, _, _, _ },
    { _, _, _, y, _, _, _ },
    { _, _, _, y, _, _, _ },
    { _, _, _, y, _, _, _ },
    { _, _, _, y, _, _, _ },
    { _, _, _, y, _, _, _ },
    { _, _, _, y, _, _, _ },
    { _, _, _, y, _, _, _ },
    { _, _, _, y, _, _, _ },
    { _, _, _, y, _, _, _ }
};

Document::Document(pro2::Pt posi, int angle) : 
    posi_(posi), rect_({posi.x, posi.y, posi.x + 6, posi.y + 12}), angle_(angle), last_paint_was_front_(false), k_(0) {}

void Document::paint(pro2::Window& window) const {
    if (this->angle_ == 0) this->paint_front_(window);
    else if (this->angle_ == 30) this->paint_midfront_(window);
    else if (this->angle_ == 70) this->paint_midsite_(window);
    else this->paint_site_(window);
}

void Document::update() {
    if (this->k_ >= this->fps_cycle_) {
        if (this->angle_ == 0) {
            this->angle_ = 30;
            this->last_paint_was_front_ = true;
        }
        else if (this->angle_ == 30) {
            if (this->last_paint_was_front_) this->angle_ = 70;
            else this->angle_ = 0;
        }
        else if (this->angle_ == 70) {
            if (this->last_paint_was_front_) this->angle_ = 90;
            else this->angle_ = 30;
        }
        else {
            this->angle_ = 70;
            this->last_paint_was_front_ = false;
        }
        this->k_ = 0;
    }
    else this->k_++;
}

void Document::changehigh(int h) {
    this->posi_.y = h;
}

void Document::paint_front_(pro2::Window& window) const {
    pro2::paint_sprite(window, this->posi(), this->document_sprite_front(), false);
}

void Document::paint_midfront_(pro2::Window& window) const {
    pro2::paint_sprite(window, this->posi(), this->document_sprite_midfront(), false);
}

void Document::paint_midsite_(pro2::Window& window) const {
    pro2::paint_sprite(window, this->posi(), this->document_sprite_midsite(), false);
}

void Document::paint_site_(pro2::Window& window) const {
    pro2::paint_sprite(window, this->posi(), this->document_sprite_site(), false);
}
