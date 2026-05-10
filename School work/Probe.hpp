#pragma once

namespace pda {
	template <int N = 1>
	class Probe {
	private:
		inline static long counter[6];
		char dummy[N];

	public:
		Probe() { ++counter[0]; }
		static int ctor_count() { return static_cast<int>(counter[0]); }

		Probe(const Probe&) { ++counter[1]; }
		static int copy_count() { return static_cast<int>(counter[1]); }

		Probe(Probe&&) { ++counter[2]; }
		static int move_count() { return static_cast<int>(counter[2]); }

		Probe& operator=(const Probe& other) {
			++counter[3];
			return *this;
		}
		static int copy_assign_count() { return static_cast<int>(counter[3]); }

		Probe& operator=(Probe&& other) {
			++counter[4];
			return *this;
		}
		static int move_assign_count() { return static_cast<int>(counter[4]); }

		~Probe() { ++counter[5]; }
		static int dtor_count() { return static_cast<int>(counter[5]); }
	};
}  // namespace pda