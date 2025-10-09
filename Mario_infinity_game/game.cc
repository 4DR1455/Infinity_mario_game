//I JUST DID THE IMPLEMENTATIONS OF THE FUNCTIONS, NOT THE CLASS.

#include "game.hh"
#include "utils.hh"

Game::Game(int width, int height)
    : mario_({width / 2, 150}, 'A', 'D', 'W'),
      platforms_{},
      finished_(false),
      paused_(false),
      g_o(false),
      explode_(false),
      k_(0),
      docus_took_(0),
      documents_({0,0,width, height}),
      ds_{},
      hummers_({0,0,width, height}),
      hs_{},
      bombs_({0,0,width, height}),
      bs_{},
      file("output.txt")
{
    platforms_.push_back(Platform(0,0,0,0,0,0)); //Fake platform to avoid that platform desapear from screen.
    platforms_.push_back(Platform(0,0,0,0,0,0)); //Fake platform to avoid that platform desapear from screen
    platforms_.push_back(Platform(100, 300, 200, 211, 0,0));
    platforms_.push_back(Platform(250, 400, 150, 161, 250, 261));
    platforms_.push_back(Platform(450, 600, 150, 161, 150, 161));
}


void Game::process_keys(pro2::Window& window) {
    if (window.is_key_down(pro2::Keys::P)) {
        if (!paused_) paused_ = true;
        else if(paused_) paused_ = false;
    }
    if (window.is_key_down(pro2::Keys::Escape)) {
        finished_ = true;
        return;
    }
}

void Game::update_objects(pro2::Window& window) {
    pro2::Pt posM = mario_.pos();
    //Capture document
    std::set<Document *> docs_ = documents_.query(mario_.get_rect());
    for (auto d : docs_) {
        documents_.remove(d);
        auto it = ds_.begin();
        while (&*it != d) it++;
        ds_.erase(it);
        docus_took_++;
    }
    documents_.update_rect(window.camera_rect());

    //Kill mario
    std::set<Hummer *> hums_ = hummers_.query(mario_.get_rect());
    for (auto h : hums_) {
        h->attack();
        if (h->get_rect().top > window.camera_rect().bottom) {
            hummers_.remove(h);
            auto it = hs_.begin();
            while (&*it != h) it++;
            hs_.erase(it);
        }
    }
    hummers_.update_rect(window.camera_rect());

    //Deactivate bomba
    std::set<Bomb *> bms_ = bombs_.query(mario_.get_rect());
    for (auto b : bms_) {
        if (docus_took_ > 0) {
            bombs_.remove(b);
            auto it = bs_.begin();
            while (&*it != b) it++;
            bs_.erase(it);
            docus_took_--;
        }
    }
    bombs_.update_rect(window.camera_rect());

    mario_.update(window, platforms_);
    if (mario_.get_rect().top > window.camera_rect().bottom) g_o = true;

    auto pl = platforms_.rbegin();
    pl++;

    if (mario_.pos().x + 50 > pl->get_rect().right) {
        //new pl
        pro2::Rect last_platform = platforms_.back().get_rect();
        int new_top;
        if (last_platform.top - 20 < MAX_UP) new_top = pro2::nombre_aleatori(MAX_UP, last_platform.top + 40);
        else if (last_platform.top + 20 > MAX_DOWN) new_top = pro2::nombre_aleatori(last_platform.top - 40, MAX_DOWN);
        else new_top = pro2::nombre_aleatori(last_platform.top - 40, last_platform.top + 40);
        int new_left = pro2::nombre_aleatori(last_platform.right + 5, last_platform.right + 60);
        platforms_.push_back(Platform(new_left, new_left + 100, new_top, new_top + 11, last_platform.top, last_platform.bottom));
        
        pro2::Rect last_p_rect = platforms_.back().get_rect();
        int spawn_chance = pro2::nombre_aleatori(0,4);
        bool h_spawned = false, d_spawned = false;

        //new hummer
        if (spawn_chance < 1) {
            hs_.push_back(Hummer({(last_p_rect.left + last_p_rect.right)/2, last_p_rect.top - 33}));
            hummers_.add(&hs_.back());
            h_spawned = true;
        }
        
        spawn_chance = pro2::nombre_aleatori(0,4);
        //new doc
        if (spawn_chance < 3) {
            int high = new_top - pro2::nombre_aleatori(14,54);
            if (h_spawned && high < hs_.back().get_rect().bottom && high + 12 > hs_.back().get_rect().top) high -= (high + 18 - hs_.back().get_rect().top);
            ds_.push_back(Document({(last_p_rect.left + last_p_rect.right)/2, high},0));
            documents_.add(&(ds_.back()));
            d_spawned = true;
        }

        spawn_chance = pro2::nombre_aleatori(0,4);
        //new bomb
        if (!h_spawned && !d_spawned && (ds_.size() + docus_took_) >= bs_.size() + 1 && spawn_chance < 2) {
            bs_.push_back(Bomb({(last_p_rect.left + last_p_rect.right)/2, last_p_rect.top - 19}, 10));
            bombs_.add(&(bs_.back()));
        }
        
        platforms_.pop_front();
    }
}

void Game::update_camera(pro2::Window& window) {
    const pro2::Pt pos = mario_.pos();
    const pro2::Pt cam = window.camera_center();

    if (abs(pos.x - cam.x) > 0) {
        window.move_camera({pos.x-cam.x, 0});
    }
}

void Game::update(pro2::Window& window) {
    process_keys(window);
    if (!paused_ && !g_o && !explode_) {
        update_objects(window);
        update_camera(window);
    }
    else if (g_o) {
        if (window.is_key_down(pro2::Space)) {
            mario_ = Mario({window.width() / 2, 150}, 'A', 'D', 'W');
            platforms_.clear();
            finished_ = false;
            paused_ = false;
            g_o = false;
            k_ = 0;
            docus_took_ = 0;
            documents_.reset({0,0,window.width(), window.height()});
            hummers_.reset({0,0,window.width(), window.height()});
            bombs_.reset({0,0,window.width(), window.height()});
            ds_.clear();
            hs_.clear();
            bs_.clear();
            window.set_camera_topleft({0,0});
            platforms_.push_back(Platform(0,0,0,0,0,0)); //Fake platform to avoid that platform desapear from screen.
            platforms_.push_back(Platform(0,0,0,0,0,0)); //Fake platform to avoid that platform desapear from screen.
            platforms_.push_back(Platform(100, 300, 200, 211, 0,0));
            platforms_.push_back(Platform(250, 400, 150, 161, 250, 261));
            platforms_.push_back(Platform(450, 600, 150, 161, 150, 161));
        }
    }
    else if (explode_) k_++;
}

void Game::paint(pro2::Window& window) {
    pro2::Rect wr = window.camera_rect();
    if (explode_) {
        if (k_ < 12)
        if (k_%3 == 1) window.clear(pro2::red);
        else if (k_%3 == 2) window.clear(pro2::yellow);
        else window.clear(pro2::white);
        else {
            g_o = true;
            explode_ = false;
        }
    }
    else if (g_o) {
        window.clear(pro2::black);
        pro2::paint_sprite(window, {wr.left + 50, wr.top + 50}, escala(game_over, 4), false);
        pro2::paint_sprite(window, {wr.left + 50, wr.top + 122}, escala(ds_.front().document_sprite_front(), 3), false);
        pro2::paint_sprite(window, {wr.left + 90, wr.top + 138}, escala(s_dp, 2), false);
        
        const int ST = 35;

        std::string docus_took_str = std::to_string(docus_took_);
        int d_t_size = docus_took_str.size();
        int dt_ = docus_took_;

        for (int i = d_t_size - 1 ; i >= 0; i--) {
            switch (dt_%10)
            {
                case 0:
                pro2::paint_sprite(window, {wr.left + 125 + ST*i, wr.top + 130}, escala(n_0, 3), false); 
                break;
                case 1:
                pro2::paint_sprite(window, {wr.left + 125 + ST*i, wr.top + 130}, escala(n_1, 3), false); 
                break;
                case 2:
                pro2::paint_sprite(window, {wr.left + 125 + ST*i, wr.top + 130}, escala(n_2, 3), false); 
                break;
                case 3:
                pro2::paint_sprite(window, {wr.left + 125 + ST*i, wr.top + 130}, escala(n_3, 3), false); 
                break;
                case 4:
                pro2::paint_sprite(window, {wr.left + 125 + ST*i, wr.top + 130}, escala(n_4, 3), false); 
                break;
                case 5:
                pro2::paint_sprite(window, {wr.left + 125 + ST*i, wr.top + 130}, escala(n_5, 3), false); 
                break;
                case 6:
                pro2::paint_sprite(window, {wr.left + 125 + ST*i, wr.top + 130}, escala(n_6, 3), false); 
                break;
                case 7:
                pro2::paint_sprite(window, {wr.left + 125 + ST*i, wr.top + 130}, escala(n_7, 3), false); 
                break;
                case 8:
                pro2::paint_sprite(window, {wr.left + 125 + ST*i, wr.top + 130}, escala(n_8, 3), false); 
                break;
                case 9:
                pro2::paint_sprite(window, {wr.left + 125 + ST*i, wr.top + 130}, escala(n_9, 3), false); 
                break;
                default:
                break;
            }
            dt_ = dt_ / 10;
        }
        
        pro2::paint_sprite(window, {wr.left + 50, wr.top + 200}, escala(play_again, 2), false);
    }
    else if (!paused_) {
        window.clear(sky_blue);
        
        //Landscape:
        pro2::paint_sprite(window, {wr.right - 45, wr.top}, escala(sol_, 5), false);
        pro2::paint_sprite(window, {wr.left, wr.top + window.width()/4 - 70},escala(paissatge_, 10), false);        

        for (const Platform& p : platforms_) {
            p.paint(window);
        }
        
        std::set<Document *> docs_ = documents_.query(wr);
        for (auto d : docs_) {
            d->update();
            d->paint(window);
            if (d->get_rect().right - 40 < wr.left) {
                documents_.remove(d);
                auto it = ds_.begin();
                while (&*it != d) it++;
                ds_.erase(it);
            }
        }
        std::set<Hummer *> hums_ = hummers_.query(wr);
        for (auto h : hums_) {
            h->update();
            h->paint(window);
            if (h->colliding(mario_.get_rect())) g_o = true;
            if (h->get_rect().right - 40 < wr.left) {
                hummers_.remove(h);
                auto it = hs_.begin();
                while (&*it != h) it++;
                hs_.erase(it);
            }
        }
        std::set<Bomb *> bms_ = bombs_.query(wr);
        for (auto b : bms_) {
            b->update();
            b->paint(window);
            if (b->get_rect().right - 40 < wr.left) {
                bombs_.remove(b);
                auto it = bs_.begin();
                while (&*it != b) it++;
                bs_.erase(it);
            }
            else if (b->explode(window)) explode_ = true;
        }
        mario_.paint(window);
        
        //ui:
        std::string docus_took_str = std::to_string(docus_took_);
        int d_t_size = docus_took_str.size();
        int dt_ = docus_took_;
        const int ST = 5;
        
        pro2::paint_sprite(window, {wr.left + 15, wr.top + 5}, s_dp, false);
        pro2::paint_sprite(window, {wr.left + 5, wr.top + 5}, ds_.front().document_sprite_front(), false);

        for (int i = d_t_size - 1 ; i >= 0; i--) {
            switch (dt_%10)
            {
                case 0:
                pro2::paint_sprite(window, {wr.left + 25 + ST*i, wr.top + 5}, n_0, false); 
                break;
                case 1:
                pro2::paint_sprite(window, {wr.left + 25 + ST*i, wr.top + 5}, n_1, false); 
                break;
                case 2:
                pro2::paint_sprite(window, {wr.left + 25 + ST*i, wr.top + 5}, n_2, false); 
                break;
                case 3:
                pro2::paint_sprite(window, {wr.left + 25 + ST*i, wr.top + 5}, n_3, false); 
                break;
                case 4:
                pro2::paint_sprite(window, {wr.left + 25 + ST*i, wr.top + 5}, n_4, false); 
                break;
                case 5:
                pro2::paint_sprite(window, {wr.left + 25 + ST*i, wr.top + 5}, n_5, false); 
                break;
                case 6:
                pro2::paint_sprite(window, {wr.left + 25 + ST*i, wr.top + 5}, n_6, false); 
                break;
                case 7:
                pro2::paint_sprite(window, {wr.left + 25 + ST*i, wr.top + 5}, n_7, false); 
                break;
                case 8:
                pro2::paint_sprite(window, {wr.left + 25 + ST*i, wr.top + 5}, n_8, false); 
                break;
                case 9:
                pro2::paint_sprite(window, {wr.left + 25 + ST*i, wr.top + 5}, n_9, false); 
                break;
                default:
                break;
            }
            dt_ = dt_ / 10;
        }

        pro2::paint_hline(window, window.camera_center().x - window.width()/2, window.camera_center().x + window.width()/2, window.camera_center().y - window.height()/2 + 1);
        pro2::paint_hline(window, window.camera_center().x - window.width()/2, window.camera_center().x + window.width()/2, window.camera_center().y - window.height()/2);
        pro2::paint_hline(window, window.camera_center().x - window.width()/2, window.camera_center().x + window.width()/2, window.camera_center().y + window.height()/2 - 2);
        pro2::paint_hline(window, window.camera_center().x - window.width()/2, window.camera_center().x + window.width()/2, window.camera_center().y + window.height()/2 - 1);
        pro2::paint_vline(window, window.camera_center().x - window.width()/2 + 1, window.camera_center().y - window.height()/2, window.camera_center().y + window.height()/2);
        pro2::paint_vline(window, window.camera_center().x - window.width()/2, window.camera_center().y - window.height()/2, window.camera_center().y + window.height()/2);
        pro2::paint_vline(window, window.camera_center().x + window.width()/2 - 2, window.camera_center().y - window.height()/2, window.camera_center().y + window.height()/2);
        pro2::paint_vline(window, window.camera_center().x + window.width()/2 - 1, window.camera_center().y - window.height()/2, window.camera_center().y + window.height()/2);

    }
}
