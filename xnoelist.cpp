#include <iostream>

namespace xnoe {
	template<class T>
	class node {
	public:

		node<T>* pre;
		T data;
		node<T>* nex;

		node(node* p, T d, node* n) {
			pre = p;
			data = d;
			nex = n;
		}

		node(){}
	};

	template <class T>
	class list {
		node<T>* first;
		node<T>* last;

	public:
		template<size_t N>
		list(T (&arr)[N]) {
			first = new node<T>(NULL, arr[0], NULL);
			node<T>* pre = first;
			for (int i=1; i<N; i++) {
				node<T>* tmp = new node<T>(pre, arr[i], NULL);
				pre->nex = tmp;
				pre = tmp;
			}
			last = pre->nex;
		}

		T operator[](int n) {
			node<T>* tmp = first;

			for (int ind=0; tmp->nex != NULL && n != ind; ind++)
				tmp = tmp->nex;

			return tmp->data;
		}

		void append(T d) {
			last->nex = new node<T>(last, d, NULL);
			last = last->nex;
		}

		void prepend (T d) {
			first->pre = new node<T>(NULL, d, first);
			first = first->pre;
		}

		void printAll() {
			for (node<T>* current = first; current != NULL; current = current->nex)
				std::cout << current->data << (current->nex != NULL?", ":"");
		}
	};
};

int main() {
	int ints[6] = {3, 4, 5, 2, 6, 7};
	xnoe::list<int> list_of_ints = xnoe::list<int>(ints);

	std::cout << ints[4] << "\n";
	std::cout << list_of_ints[4] << "\n";

	list_of_ints.prepend(42);
	std::cout << list_of_ints[0] << "\n";

	list_of_ints.printAll();

	return 0;
}
