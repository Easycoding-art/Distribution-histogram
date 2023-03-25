#pragma once
#include "Binary_tree.h"
#include "Sequence.h"
template <typename TKey, typename TElement>
class key_value
{
public:
	TKey key;
	TElement value;
	key_value() {};
	key_value(TKey k, TElement v) {
		key = k;
		value = v;
	};

	friend bool operator ==(const key_value& element1, const key_value& element2) {
		return (element1.key == element2.key) && (element1.value == element2.value);
	}

	friend bool operator >=(const key_value& element1, const key_value& element2) {
		return element1.key >= element2.key;
	}

	friend bool operator !=(const key_value<TKey, TElement>& element1, const key_value<TKey, TElement>& element2) {
		return (element1.key != element2.key) && (element1.value != element2.value);
	}

	friend bool operator <=(const key_value& element1, const key_value& element2) {
		return element1.key <= element2.key;
	}

	friend bool operator >(const key_value& element1, const key_value& element2) {
		return element1.key > element2.key;
	}

	friend bool operator <(const key_value& element1, const key_value& element2) {
		return element1.key < element2.key;
	}
};
template <typename Key, typename Element>class IDictionary
{
public:
	IDictionary(){}
	IDictionary(Key k, Element v) {
		key_value<Key, Element> data = key_value<Key, Element>(k, v);
		elements = new binary_tree <key_value<Key, Element>>(data);
	}
	int GetCount() {
		return elements.size();
	}
	Element Get(Key k) {
		Sequence<key_value<Key, Element>> seq = elements.get_sequence();
		int size = elements.size();
		Element result;
		for (int i = 0; i < size; i++) {
			if (seq.peek(i).key == k) {
				result = seq.peek(i).value;
				break;
			}
		}
		seq.erase();
		return result;
	}
	Sequence<Key> Keys() {
		Sequence<key_value<Key, Element>> seq = elements.get_sequence();
		int size = elements.size();
		Sequence<Key> result = Sequence<Key>();
		for (int i = 0; i < size; i++) {
			result = result.add(seq.peek(i).key);
			seq.erase();
		}
		return result;
	}
	bool ContainsKey(Key k) {
		Sequence<key_value<Key, Element>> seq = elements.get_sequence();
		int size = elements.size();
		bool result = false;
		for (int i = 0; i < size; i++) {
			if (seq.peek(i).key == k) {
				result = true;
				break;
			}
			seq.erase();
		}
		return result;
	}
	void Add(Key k, Element v) {
		key_value<Key, Element> data = key_value<Key, Element>(k, v);
		elements.insert(data);
	}

private:
	binary_tree<key_value<Key, Element>> elements;
};