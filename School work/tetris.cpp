#pragma once

#include <ostream>

namespace tetris {
	class Tetromino {
	public:
		virtual ~Tetromino() = default;

	private:
		char dir;

	public:
		virtual void print(std::ostream& os) const = 0;

		virtual void rotate(int x) { dir = ((dir + x) % 4 + 4) % 4; }

		int orientation() const { return dir; }
	};

	class ITetromino : public Tetromino {
	public:
		inline static int counter = 0;

		ITetromino() { ++counter; }
		ITetromino(const ITetromino& other) { ++counter; }
		~ITetromino() { --counter; }

		void print(std::ostream& os) const override {
			if (orientation() % 2 == 0) {
				os << "####\n";
			} else {
				os << "#\n#\n#\n#\n";
			}
		}

		static int instance_count() { return counter; }
	};
}  // namespace tetris