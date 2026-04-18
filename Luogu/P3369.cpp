#include <bits/stdc++.h>
using namespace std;
class Treap {
private:
	struct Treap_Node {
		Treap_Node* ch[2];
		int val, prio, cnt, siz;

		Treap_Node(int val) : val(val), cnt(1), siz(1) {
			ch[0] = ch[1] = nullptr;
			prio = rand();
		}

		void update_size() {
			siz = cnt;
			if (ch[0] != nullptr) siz += ch[0]->siz;
			if (ch[1] != nullptr) siz += ch[1]->siz;
		}
	};

	Treap_Node* root = nullptr;

	constexpr static int NIL = -1;

	const bool LEFT = 1;
	const bool RIGHT = 0;

	void Treap_Rotate(Treap_Node*& cur, bool dir) {
		Treap_Node* tmp = cur->ch[dir];
		cur->ch[dir] = tmp->ch[!dir];
		tmp->ch[!dir] = cur;
		cur->update_size();
		tmp->update_size();
		cur = tmp;
	}

	void Treap_Insert(Treap_Node*& cur, int val) {
		if (cur == nullptr) {
			cur = new Treap_Node(val);
			return;
		} else if (val == cur->val) {
			cur->cnt++;
			cur->siz++;
		} else if (val < cur->val) {
			Treap_Insert(cur->ch[0], val);
			if (cur->ch[0]->prio < cur->prio) {
				Treap_Rotate(cur, RIGHT);
			}
			cur->update_size();
		} else {
			Treap_Insert(cur->ch[1], val);
			if (cur->ch[1]->prio < cur->prio) {
				Treap_Rotate(cur, LEFT);
			}
			cur->update_size();
		}
	}

	void Treap_Delete(Treap_Node*& cur, int val) {
		if (cur == nullptr) return;
		if (val < cur->val) {
			Treap_Delete(cur->ch[0], val);
			cur->update_size();
			return;
		} else if (val > cur->val) {
			Treap_Delete(cur->ch[1], val);
			cur->update_size();
			return;
		} else {
			if (cur->cnt > 1) {
				cur->cnt--;
				cur->siz--;
				return;
			}
		}

		int state = 0;
		state |= (cur->ch[0] != nullptr);
		state |= ((cur->ch[1] != nullptr) << 1);
		Treap_Node* tmp = cur;
		switch (state) {
			case 0:
				delete cur;
				cur = nullptr;
				break;
			case 1:
				cur = tmp->ch[0];
				delete tmp;
				break;
			case 2:
				cur = tmp->ch[1];
				delete tmp;
				break;
			case 3:
				bool dir = cur->ch[0]->prio < cur->ch[1]->prio ? RIGHT : LEFT;
				Treap_Rotate(cur, dir);
				Treap_Delete(cur->ch[!dir], val);
				cur->update_size();
				break;
		}
	}

	int Treap_Query_Rank(Treap_Node* cur, int val) {
		if (cur == nullptr) return 1;
		int less_size = cur->ch[0] == nullptr ? 0 : cur->ch[0]->siz;
		if (val == cur->val) {
			return less_size + 1;
		} else if (val < cur->val) {
			return Treap_Query_Rank(cur->ch[0], val);
		} else {
			return less_size + cur->cnt + Treap_Query_Rank(cur->ch[1], val);
		}
	}

	int Treap_Query_Value(Treap_Node* cur, int rank) {
		int less_size = cur->ch[0] == nullptr ? 0 : cur->ch[0]->siz;
		if (rank <= less_size)
			return Treap_Query_Value(cur->ch[0], rank);
		else if (rank > less_size + cur->cnt)
			return Treap_Query_Value(cur->ch[1], rank - less_size - cur->cnt);
		else
			return cur->val;
	}

	int Treap_Query_Prev(Treap_Node* cur, int val) {
		int ans = NIL;
		while (cur != nullptr) {
			if (cur->val < val) {
				ans = cur->val;
				cur = cur->ch[1];
			} else {
				cur = cur->ch[0];
			}
		}
		return ans;
	}

	int Treap_Query_Next(Treap_Node* cur, int val) {
		int ans = NIL;
		while (cur != nullptr) {
			if (cur->val > val) {
				ans = cur->val;
				cur = cur->ch[0];
			} else {
				cur = cur->ch[1];
			}
		}
		return ans;
	}

public:
	void insert(int val) { Treap_Insert(root, val); }
	void del(int val) { Treap_Delete(root, val); }
	int query_rank(int val) { return Treap_Query_Rank(root, val); }
	int query_val(int rank) { return Treap_Query_Value(root, rank); }
	int query_prev(int val) { return Treap_Query_Prev(root, val); }
	int query_next(int val) { return Treap_Query_Next(root, val); }
} tr;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(nullptr));
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int op, x;
		cin >> op >> x;
		switch (op) {
			case 1:
				tr.insert(x);
				break;
			case 2:
				tr.del(x);
				break;
			case 3:
				cout << tr.query_rank(x) << '\n';
				break;
			case 4:
				cout << tr.query_val(x) << '\n';
				break;
			case 5:
				cout << tr.query_prev(x) << '\n';
				break;
			case 6:
				cout << tr.query_next(x) << '\n';
				break;
		}
	}
	return 0;
}