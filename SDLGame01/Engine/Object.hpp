#pragma once

namespace SDLEngine {

	class SDLObject {

	public:
		virtual void render() = 0;
		virtual void update() = 0;
	};

}