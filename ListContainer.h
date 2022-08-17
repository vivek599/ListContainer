#pragma once

template<class T>
class ListContainer
{
private:
	struct Node
	{
		Node* Next;
		T Value;
	};

	Node* m_Root = nullptr;
	Node* m_Current = nullptr;
	Node* m_NextNode = nullptr;

	void NewNode(T Value)
	{
		if (m_Root == nullptr)
		{
			m_Root = new Node();
			m_Root->Next = nullptr;
			m_Root->Value = Value;
			m_Current = m_Root;
		}
		else
		{
			m_Current->Next = new Node();
			m_Current->Next->Next = nullptr;
			m_Current->Next->Value = Value;

			m_Current = m_Current->Next;
		}

		m_NextNode = m_Root;
	}

public:
	ListContainer()
	{

	}

	~ListContainer()
	{
		while (m_Root)
		{
			Node* Temp = m_Root;
			m_Root = Temp->Next;
			delete Temp;
			Temp = nullptr;
		}
	}

	void PushElement(T Element)
	{
		NewNode(Element);
	}

	void RemoveElement(T Element)
	{
		Node* Temp = m_Root;
		Node* Prev = nullptr;

		while (Temp->Value != Element)
		{
			Prev = Temp;
			Temp = Temp->Next;
		}
		
		Prev->Next = Temp->Next;
		delete Temp;
		Temp = nullptr;
	}

	T NextValue()
	{
		T Val;
		if (m_NextNode)
		{
			Val = m_NextNode->Value;
			m_NextNode = m_NextNode->Next;
		}

		return Val;
	}

	int GetLength()
	{
		int Length = 0;

		Node* N = m_Root;

		while (N)
		{
			Length++;
			N = N->Next;
		}

		return Length;
	}


};

