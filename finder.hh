#ifndef FINDER_HH
#define FINDER_HH

#include <memory>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include "geometry.hh"

template <typename T>

class Finder;

template <typename T>

//subFinders is a Quaternary tree where each not leaf node has 4 branches, this way screen divides itself into n^4 pices, and at the end, when pices are too small they have a map of <T *, Rect> where Rect is the hitbox and position of T. This way finding colliding objacts, updating, adding or destroying them has O(logn) cost.
class subFinder {
 public:
    subFinder(pro2::Rect r) 
      : rect_(r), final_(false) {
        if (r.bottom - r.top <= MIN_SIZE) {
            f_final_ = {};
            final_ = true;
        }
    }

    /**
     * @brief subFinder.add() finds all leaves that collide with @a r and adds the pointer and T's Rect to each leaf's map. It also returns a vector with pointers to all the leaves, so next accesses can be quicker.
     * @pre A subFinder where that hadn't registered any pointer of @a t.
     * @post subFinder now has @a t registered on the correct leaves and returns a vector of pointers to the leaves that @a t collides with.
     * @param t A pointer to a T class type object.
     * @param r The Rect of @a t.
     */
    std::vector<subFinder<T> *> add( T *t, const pro2::Rect r) {
        if (final_) {
            f_final_.insert_or_assign(t, r);
            return {this};
        }
        else{
            std::vector<subFinder<T> *> result;
            if (finders_00_ == nullptr)
                finders_00_ = std::make_unique<subFinder<T>>(pro2::Rect{rect_.left, rect_.top, (rect_.left + rect_.right)/2, (rect_.top + rect_.bottom)/2});
            if (colliding(r, finders_00_->get_rect())) {
                std::vector<subFinder<T> *> r_ = finders_00_->add(t, r);
                for (auto v : r_) result.push_back(v);
            }
            if (finders_01_ == nullptr)
                finders_01_ = std::make_unique<subFinder<T>>(pro2::Rect{(rect_.left + rect_.right)/2, rect_.top, rect_.right, (rect_.top + rect_.bottom)/2});
            if (colliding(r, finders_01_->get_rect())) {
                std::vector<subFinder<T> *> r_ = finders_01_->add(t, r);
                for (auto v : r_) result.push_back(v);
            }
            if (finders_10_ == nullptr)
                finders_10_ = std::make_unique<subFinder<T>>(pro2::Rect{rect_.left, (rect_.top + rect_.bottom)/2, (rect_.left + rect_.right)/2, rect_.bottom}); 
            if (colliding(r, finders_10_->get_rect())) {
                std::vector<subFinder<T> *> r_ = finders_10_->add(t, r);
                for (auto v : r_) result.push_back(v);
            }
            if (finders_11_ == nullptr)
                finders_11_ = std::make_unique<subFinder<T>>(pro2::Rect{(rect_.left + rect_.right)/2, (rect_.top + rect_.bottom)/2, rect_.right, rect_.bottom});
            if (colliding(r, finders_11_->get_rect())) {
                std::vector<subFinder<T> *> r_ = finders_11_->add(t, r);
                for (auto v : r_) result.push_back(v);
            }
            return result;
        }
    }

    /**
     * @brief subFinder.update() updates @a t data.
     * @pre subFinder has @a t wrong data.
     * @post subFinder has @a t correct data.
     * @param t The pointer aiming to the object that we want to update data.
     * @param r The Rect of the T object where @a t aims.
     */
    void update( T *t, const pro2::Rect r) {
        this->remove(t, r);
        this->add(t, r);
    }

    /**
     * @brief subFinder.remove() deletes @a t and its data.
     * @pre subFinder has the pointer @a t and its corresponding data.
     * @post subFinder does not have any more @a t nor its data.
     * @param t The pointer that we want to delete.
     */
    void remove( T *t) {
        if (t != nullptr && final_ && f_final_.find(t) != f_final_.end()) f_final_.erase(t);
        else {
            if (finders_00_ != nullptr) finders_00_->remove(t);
            if (finders_01_ != nullptr) finders_01_->remove(t);
            if (finders_10_ != nullptr) finders_10_->remove(t);
            if (finders_11_ != nullptr) finders_11_->remove(t);
        }
    }

    /**
     * @brief subFinder.get_rect() returns the Rect properties of the subFinder.
     */
    pro2::Rect get_rect() const {return rect_;}

    /**
     * @brief subFinder.change_rect() changes the Rect of the subFinder, it supposes there is no data inside the subFinder.
     * @pre Empty subFinder with some rect and no data.
     * @post Empty subFinder with another rect and no data.
     * @param rect The new Rect of the subFinder.
     */
    void change_rect(pro2::Rect rect) {
        rect_ = rect;
        if (final_) {rect_ = rect;}
        else {
            if (finders_00_ != nullptr) finders_00_->change_rect(rect);
            if (finders_01_ != nullptr) finders_01_->change_rect(rect);
            if (finders_10_ != nullptr) finders_10_->change_rect(rect);
            if (finders_11_ != nullptr) finders_11_->change_rect(rect);
        }
    }

    /**
     * @brief subFinder.clear() deletes all branches and data inside them.
     */
    void clear() {
        finders_00_.~unique_ptr();
        finders_01_.~unique_ptr();
        finders_10_.~unique_ptr();
        finders_11_.~unique_ptr();
    }

    /**
     * @brief subFinder.query() adds at @a set of all the T * that collide with @a qrect.
     * @pre The Finder and @a qrect, and a a set.
     * @post The very same Finder, the very same @a qrect and the set with pointers to all T objects colliding with @a qrect added to it.
     * @param qrect A Rect.
     * @param r The set of T *.
     */
    void query(pro2::Rect qrect, std::set< T *> &r) const {
        if (final_) {
            for (auto f : f_final_) {
                if (colliding(f.second, qrect)) r.insert(f.first);
            }
        }
        else {
            if (finders_00_ != nullptr && colliding(finders_00_->get_rect(), qrect)) finders_00_->query(qrect, r);
            if (finders_01_ != nullptr && colliding(finders_01_->get_rect(), qrect)) finders_01_->query(qrect, r);
            if (finders_10_ != nullptr && colliding(finders_10_->get_rect(), qrect)) finders_10_->query(qrect, r);
            if (finders_11_ != nullptr && colliding(finders_11_->get_rect(), qrect)) finders_11_->query(qrect, r);
        }
    }

 private:

    /**
    * @brief Returns if @a rect1 and @a rect2 collide.
    * @pre 2 Rect.
    * @post A boolean.
    * @param rect1 First Rect.
    * @param rect2 Second Rect.
    */    
    static bool colliding(const pro2::Rect f_rect, const pro2::Rect qrect) {
        bool vertical = (f_rect.top <= qrect.bottom && f_rect.bottom >= qrect.top);
        bool horizontal = (f_rect.right >= qrect.left && f_rect.left <= qrect.right);
        return vertical && horizontal;
    }

    const int MIN_SIZE = 20;   //20 is empirically the best size to optimize subFinder performance.
    
    pro2::Rect rect_;   //Rect data's node.

    bool final_;

    std::map< T*, pro2::Rect> f_final_;    //The map where colliding T pointers are stored with their Rect-associated data.

    //Pointers to subFinder's branches. They get initialized on subFinder.add()'s demand.
    std::unique_ptr<subFinder<T>> finders_00_;
    std::unique_ptr<subFinder<T>> finders_01_;
    std::unique_ptr<subFinder<T>> finders_10_;
    std::unique_ptr<subFinder<T>> finders_11_;

};

//This class is a mask class, it aims to make it easier for the user to manage the quaternary tree, so it doesen't need to deal with tricky pointers.
template <typename T>
class Finder {
 public:
    Finder(pro2::Rect rect) : rect_({rect.left, rect.top, rect.right*3 - rect.left, rect.bottom}), finders_0(rect), 
    finders_1({rect.right, rect.top, 2*rect.right - rect.left, rect.bottom}), finders_2({2*rect.right, rect.top, 3*rect.right-rect.left, rect.bottom}), 
    size_(0) {}

    int size() {return size_;}

    /**
     * @brief Finder.add() stores the @a t pointer and its data to the Finder leaves where the T object collides. It also stores pointers to the leaf so next accesses are quicker.
     * @pre A pointer of a T class object and a Finder where the T object is not stored.
     * @post It does not return anything, but it stores data to the data structure.
     * @param t A pointer to the T object that we want to add.
     */
    void add(T *t) {
        const pro2::Rect rect = t->get_rect();
        if (colliding(rect, finders_0.get_rect())) {
            std::vector<subFinder<T> *> result = finders_0.add(t, rect);
            subFinders_[t].insert(result.begin(), result.end());
            if (result.size() > 0) size_++;
        }
        if (colliding(rect, finders_1.get_rect())) {
            std::vector<subFinder<T> *> result = finders_1.add(t, rect);
            subFinders_[t].insert(result.begin(), result.end());
            if (result.size() > 0) size_++;
        }
        if (colliding(rect, finders_2.get_rect())) {
            std::vector<subFinder<T> *> result = finders_2.add(t, rect);
            subFinders_[t].insert(result.begin(), result.end());
            if (result.size() > 0) size_++;
        }
    }

    /**
     * @brief Finder.update() updates the information of @a t object.
     * @pre Finder has wrong data.
     * @post Finder has correct data.
     * @param t The pointer we want to update.
     */
    void update(T *t) {
        this->remove(t);
        this->add(t);
    }

    /**
     * @brief Finder.remove() deletes all @a t and all its associated data.
     * @pre El finder amb el punter que es vol esborrar registrat.
     * @pre Finder has @a t pointer and its data stored.
     * @post Finder has not @a t pointer and its data stored
     * @param t The pointer we want to remove.
     */
    void remove(T *t) {
        if (t != nullptr && subFinders_.find(t) != subFinders_.end()) {
            for (auto sf : subFinders_[t]) { //Hi ha un error
                if (sf != nullptr) sf->remove(t);
                else subFinders_[t].erase(sf);
            }
            subFinders_.erase(t);
            size_--;
        }
    }

    /**
     * @brief Returns Finder's Rect.
     */
    pro2::Rect get_rect() const {return rect_;}

    /**
     * @brief This function is only created to allow the game to be infinite. Finder.update_rect() clears all data from the subFinder that the camera is not using, known based on @a ref, anymore and moves it to the right so it can be used again.
     * @pre 1/3 of the finder is not being used, and it won't be used anymore.
     * @post All finder is being used or going to be used.
     * @param ref Camera's Rect.
     */
    void update_rect(pro2::Rect ref) {
        pro2::Rect r0 = finders_0.get_rect();
        pro2::Rect r1 = finders_1.get_rect();
        pro2::Rect r2 = finders_2.get_rect();
        if (r0.right - 50 < ref.left) {
            finders_0.clear();
            finders_0.change_rect({r2.right, ref.top, r2.right + (ref.right - ref.left), ref.bottom});
            rect_ = {r1.left, ref.top, finders_0.get_rect().right, ref.bottom};
        }
        if (r1.right - 50 < ref.left) {
            finders_1.clear();
            finders_1.change_rect({r0.right, ref.top, r0.right + (ref.right - ref.left), ref.bottom});
            rect_ = {r2.left, ref.top, finders_1.get_rect().right, ref.bottom};
        }
        if (r2.right - 50 < ref.left) {
            finders_2.clear();
            finders_2.change_rect({r1.right, ref.top, r1.right + (ref.right - ref.left), ref.bottom});
            rect_ = {r0.left, ref.top, finders_2.get_rect().right, ref.bottom};
        }
    }

    /**
     * @brief Finder.reset() resets Finder, starting at @a rect.
     * @pre Used finder with some data and at some Rect.
     * @post Unused finder starting at @a rect.
     * @param rect The Rect where we want to start Finder.
     */
    void reset(pro2::Rect rect) {
        subFinders_.clear();
        finders_0.clear();
        finders_1.clear();
        finders_2.clear();
        finders_0.change_rect(rect);
        finders_1.change_rect({rect.right, rect.top, 2*rect.right - rect.left, rect.bottom});
        finders_2.change_rect({2*rect.right, rect.top, 3*rect.right - rect.left, rect.bottom});
    }

    /**
     * @brief Finder.query() returns a set of all the T * that collide with @a qrect.
     * @pre The Finder and @a qrect.
     * @post The very same Finder, the very same @a qrect and a set with pointers to all T objects colliding with @a qrect.
     * @param qrect A Rect.
     */
    std::set< T *> query(pro2::Rect qrect) const {
        std::set< T *> r;
        if (colliding(finders_0.get_rect(), qrect)) finders_0.query(qrect, r);
        if (colliding(finders_1.get_rect(), qrect)) finders_1.query(qrect, r);
        if (colliding(finders_2.get_rect(), qrect)) finders_2.query(qrect, r);
        return r;
    }

 private:

    /**
     * @brief Retorna true si els rectangles @a rect1 i @a rect2 intersequen.
     * @pre 2 rectangles.
     * @post Un boolea.
     * @param rect1 Un rectangle.
     * @param rect2 L'altre rectangle.
     */
    static bool colliding(pro2::Rect rect1, pro2::Rect rect2) {
        bool vertical = (rect1.top <= rect2.bottom && rect1.bottom >= rect2.top);
        bool horizontal = (rect1.right >= rect2.left && rect1.left <= rect2.right);
        return vertical && horizontal;
    }

    pro2::Rect rect_;

    //All pointer that are added to Finder are stored in this map so we have a quicker acces to the leaves of the finder.

    std::map< T *, std::set<subFinder<T> *>> subFinders_;

    subFinder<T> finders_0;
    subFinder<T> finders_1;
    subFinder<T> finders_2;

    int size_;
};

#endif