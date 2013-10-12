//////////////////////////////////////////////////////////////////////////////
// NoLifeClient - Part of the NoLifeStory project                           //
// Copyright © 2013 Peter Atashian                                          //
//                                                                          //
// This program is free software: you can redistribute it and/or modify     //
// it under the terms of the GNU Affero General Public License as           //
// published by the Free Software Foundation, either version 3 of the       //
// License, or (at your option) any later version.                          //
//                                                                          //
// This program is distributed in the hope that it will be useful,          //
// but WITHOUT ANY WARRANTY; without even the implied warranty of           //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            //
// GNU Affero General Public License for more details.                      //
//                                                                          //
// You should have received a copy of the GNU Affero General Public License //
// along with this program.  If not, see <http://www.gnu.org/licenses/>.    //
//////////////////////////////////////////////////////////////////////////////

#include "game.hpp"
#include <nx/nx.hpp>
#include "graphics.hpp"
#include "config.hpp"
#include "time.hpp"

namespace nl {
    namespace game {
        bool over {false};
        void init() {
            config::load();
            nx::load_all();
            time::init();
            graphics::init();
        }
        void loop() {
            time::update();
            graphics::update();
        }
        void unload() {
            config::save();
            graphics::unload();

        }
        void play() {
            init();
            while (!over) loop();
            unload();
        }
        void shut_down() {
            over = true;
        }
        bool is_over() {
            return over;
        }
    }
}
