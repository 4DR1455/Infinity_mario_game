#ifndef DOCUMENT_HH
#define DOCUMENT_HH

#include <iostream>
#include <vector>
#include "window.hh"
#include "utils.hh"

class Document {
    private:
        const pro2::Rect rect_;
        pro2::Pt posi_;
        int angle_;
        int k_;
        const int fps_cycle_ = 5; //needed fps to turn 30º
        bool last_paint_was_front_;
        static const std::vector<std::vector<int>> document_sprite_front_;
        static const std::vector<std::vector<int>> document_sprite_midfront_;
        static const std::vector<std::vector<int>> document_sprite_midsite_;
        static const std::vector<std::vector<int>> document_sprite_site_;

        /**
         * @brief Document.paint_front_() paints the standard Document sprite.
         * @param window the window where this Document is painted.
         * */
        void paint_front_(pro2::Window& window) const;

        /**
         * @brief Document.paint_midfront_() paints the midfornt Document sprite.
         * @param window the window where this Document is painted.
         * */
        void paint_midfront_(pro2::Window& window) const;

        /**
         * @brief Document.paint_midside_() paints the midside Document sprite.
         * @param window the window where this Document is painted.
         * */
        void paint_midsite_(pro2::Window& window) const;

         /**
         * @brief Document.paint_side_() paints the side Document sprite.
         * @param window the window where this Document is painted.
         * */
        void paint_site_(pro2::Window& window) const;


    public:
        Document()
            : angle_(-1), posi_({-1, -1}), rect_({-1, -1, -1, -1}), last_paint_was_front_(false), k_(0) {}
        Document(const Document& other)
            : angle_(other.angle_), posi_(other.posi_), rect_(other.rect_), last_paint_was_front_(other.last_paint_was_front_), k_(other.k_) {}
        Document(pro2::Pt posi, int angle);

        /**
         * @brief Document.paint() decides which Document sprite to paint based on an animation clock.
         * @param window the window where this Document is painted.
         */
        void paint(pro2::Window& window) const;

        /**
         * @brief Document.update() makes the animation clock go on.
         */
        void update();

        /**
         * @brief Document.changehigh() changes the y coordinates of the document, it makes the minimum y coordnate of the document = to @a h.
         * @param h The new minimum y coordenate of the document.
         */
        void changehigh(int h);

        /**
         * @brief Document.get_rect() returns the Rect of the Document.
         */
        const pro2::Rect get_rect() const {return rect_;}

        /**
         * @brief Document.posi() returns the position of the Document (x & y coordinates).
         */
        const pro2::Pt posi() const {return posi_;}

        /**
         * @brief Document.angle() returns the animation counter.
         */
        const int angle() const {return angle_;}

        /**
         * @brief Document.paint_front_() paints the standard Document sprite.
         * */
        const std::vector<std::vector<int>>& document_sprite_front() const {return document_sprite_front_;}

        /**
         * @brief Document.paint_front_() paints the standard Document sprite.
         * */
        const std::vector<std::vector<int>>& document_sprite_midfront() const {return document_sprite_midfront_;}

        /**
         * @brief Document.paint_front_() paints the standard Document sprite.
         * */
        const std::vector<std::vector<int>>& document_sprite_midsite() const {return document_sprite_midsite_;}

        /**
         * @brief Document.paint_front_() paints the standard Document sprite.
         * */
        const std::vector<std::vector<int>>& document_sprite_site() const {return document_sprite_site_;}
};
#endif