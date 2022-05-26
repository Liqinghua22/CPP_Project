#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <valarray>
#include <array>
#include <set>
struct ListNode {
	int data;
	ListNode* next;
};
using namespace std;
class solution {
private:
	class bijiao {
	private:
		char max;
	public:
		bijiao(char _max) {
			max = _max;
		}
		bool operator()(char x) {
			return x > max;
		}
	};
public:

	//求包含数字，大小写字母的字符串中只包含数字的非严格递增的最长字符字串的长度
	int get_maxlen_of_substr_increase_num(string str) {
		list<char>a;
		a.push_back('0' - 1);
		int len = 0;
		int maxlen = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] >= '0' && str[i] <= '9' && count_if(a.begin(), a.end(), bijiao(str[i])) == 0) {
				a.push_back(str[i]);
				len++;
				maxlen = max(maxlen, len);
			}
			else if (str[i] >= '0' && str[i] <= '9') {
				maxlen = max(len, maxlen);
				len = 1;
				a.resize(1);
				a.push_back(str[i]);

			}
			else {
				a.resize(1);
				maxlen = max(len, maxlen);
				len = 0;
			}

		}
		return maxlen;
	}

	//合并两个有序链表
	ListNode* mergeList(ListNode* ptr1, ListNode* ptr2) {
		cout << "合并后的链表为" << endl;
		ListNode c;
		c.data = -1;
		c.next = nullptr;
		ListNode* ptr3 = &c;
		while (ptr1 != nullptr && ptr2 != nullptr) {
			if (ptr1->data < ptr2->data) {
				ptr3->next = new ListNode;
				ptr3->next->data = ptr1->data;
				ptr3->next->next = nullptr;
				ptr3 = ptr3->next;
				ptr1 = ptr1->next;
			}
			else if (ptr1->data == ptr2->data) {
				ptr3->next = new ListNode;
				ptr3->next->data = ptr1->data;
				ptr3->next->next = new ListNode;
				ptr3->next->next->data = ptr1->data;
				ptr3->next->next->next = nullptr;
				ptr3 = ptr3->next->next;
				ptr1 = ptr1->next;
				ptr2 = ptr2->next;
			}
			else {
				ptr3->next = new ListNode;
				ptr3->next->data = ptr2->data;
				ptr3->next->next = nullptr;
				ptr2 = ptr2->next;
			}
		}
		while (ptr1 != nullptr) {
			ptr3->next = new ListNode;
			ptr3->next->data = ptr1->data;
			ptr3->next->next = nullptr;
			ptr3 = ptr3->next;
			ptr1 = ptr1->next;
		}
		while (ptr2 != nullptr) {
			ptr3->next = new ListNode;
			ptr3->next->data = ptr2->data;
			ptr3->next->next = nullptr;
			ptr3 = ptr3->next;
			ptr2 = ptr2->next;
		}
		ptr3 = &c;
		ptr3 = ptr3->next;
		return ptr3;
	}

	//交换两个变量值
	template<typename T>
	void swap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}

	template<> void swap(int& a, int& b) {
		cout << a + b << endl;
	}


};