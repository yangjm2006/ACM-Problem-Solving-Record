#pragma once

#include <ostream>

namespace tetris {
	class Tetromino {
	public:
		virtual ~Tetromino() = default;

	private:
		char direction = 0;

	public:
		virtual void print(std::ostream& os) const = 0;
		virtual void rotate(int x) {
			int drt = direction + x;
			direction = static_cast<char>(drt % 4 + 4) % 4;
		}

		int orientation() const { return direction; }
	};

	class ITetromino : public Tetromino {
	private:
		inline static int count = 0;

	public:
		ITetromino() { ++count; }
		ITetromino(const ITetromino& other) { ++count; }
		~ITetromino() override { --count; }

		void print(std::ostream& os) const override {
			char drt = orientation();
			if (drt == 0 || drt == 2) {
				os << "####\n";
			} else {
				os << "#\n#\n#\n#\n";
			}
		}

		static int instance_count() { return count; }
	};
}  // namespace tetris