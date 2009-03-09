#pragma once

class TESForm;
class EffectSetting;

// this is a NiTPointerMap <UInt32, T_Data>
// todo: generalize key
template <typename T_Data>
class NiTPointerMap
{
public:
	NiTPointerMap();
	virtual ~NiTPointerMap();

	struct Entry
	{
		Entry	* next;
		UInt32	key;
		T_Data	* data;
	};

	// note: traverses in non-numerical order
	class Iterator
	{
		friend NiTPointerMap;

	public:
		Iterator(NiTPointerMap * table, Entry * entry = NULL, UInt32 bucket = 0)
			:m_table(table), m_entry(entry), m_bucket(bucket) { FindValid(); }
		~Iterator() { }

		T_Data *	Get(void);
		UInt32		GetKey(void);
		bool		Next(void);
		bool		Done(void);

	private:
		void		FindValid(void);

		NiTPointerMap	* m_table;
		Entry		* m_entry;
		UInt32		m_bucket;
	};

	virtual UInt32	CalculateBucket(UInt32 key);
	virtual bool	CompareKey(UInt32 lhs, UInt32 rhs);
	virtual void	Fn_03(void);
	virtual void	Fn_04(void);
	virtual void	Fn_05(void);
	virtual void	Fn_06(void);

	T_Data *	Lookup(UInt32 key);

	UInt32	m_numBuckets;
	Entry	** m_buckets;
	UInt32	m_numItems;
};

template <typename T_Data>
T_Data * NiTPointerMap <T_Data>::Lookup(UInt32 key)
{
	for(Entry * traverse = m_buckets[key % m_numBuckets]; traverse; traverse = traverse->next)
		if(traverse->key == key)
			return traverse->data;
	
	return NULL;
}

template <typename T_Data>
T_Data * NiTPointerMap <T_Data>::Iterator::Get(void)
{
	if(m_entry)
		return m_entry->data;

	return NULL;
}

template <typename T_Data>
UInt32 NiTPointerMap <T_Data>::Iterator::GetKey(void)
{
	if(m_entry)
		return m_entry->key;

	return 0;
}

template <typename T_Data>
bool NiTPointerMap <T_Data>::Iterator::Next(void)
{
	if(m_entry)
		m_entry = m_entry->next;

	while(!m_entry && (m_bucket < (m_table->m_numBuckets - 1)))
	{
		m_bucket++;

		m_entry = m_table->m_buckets[m_bucket];
	}

	return m_entry != NULL;
}

template <typename T_Data>
bool NiTPointerMap <T_Data>::Iterator::Done(void)
{
	return m_entry == NULL;
}

template <typename T_Data>
void NiTPointerMap <T_Data>::Iterator::FindValid(void)
{
	// validate bucket
	if(m_bucket >= m_table->m_numBuckets) return;

	// get bucket
	m_entry = m_table->m_buckets[m_bucket];

	// find non-empty bucket
	while(!m_entry && (m_bucket < (m_table->m_numBuckets - 1)))
	{
		m_bucket++;

		m_entry = m_table->m_buckets[m_bucket];
	}
}

extern NiTPointerMap <TESForm>			* g_formTable;
extern NiTPointerMap <EffectSetting>	* g_EffectSettingCollection;	// object is more complex than this

class TESObjectCELL;

// 004?
class TESChildCell
{
public:
	TESChildCell();
	~TESChildCell();

	// no virtual destructor
	virtual TESObjectCELL *	GetChildCell(void);
};

class BSSimpleList
{
public:
	BSSimpleList();
	~BSSimpleList();

	virtual void	Destructor(void);
};

// 8
class String
{
public:
	String();
	~String();

	char	* m_data;
	UInt16	m_dataLen;
	UInt16	m_bufLen;

	bool	Set(const char * src);
	bool	Includes(const char* toFind) const;
	bool	Replace(const char* toReplace, const char* replaceWith); // replaces instance of toReplace with replaceWith
	bool	Append(const char* toAppend);
	double	Compare(const String& compareTo, bool caseSensitive = false);
};

// not sure how much of this is in NiTListBase and how much is in NiTPointerListBase
// 10
template <typename T>
class NiTListBase
{
public:
	NiTListBase();
	~NiTListBase();

	// may also be next, prev, data
	struct Node
	{
		Node	* next;
		Node	* prev;
		T		* data;
	};

	virtual void	Destructor(void);
	virtual Node *	AllocateNode(void);
	virtual void	FreeNode(Node * node);

//	void	** _vtbl;	// 000
	Node	* start;	// 004
	Node	* end;		// 008
	UInt32	numItems;	// 00C
};

template <typename T>
class NiTPointerListBase : public NiTListBase <T>
{
public:
	NiTPointerListBase();
	~NiTPointerListBase();
};

template <typename T>
class NiTPointerList : public NiTPointerListBase <T>
{
public:
	NiTPointerList();
	~NiTPointerList();
};

extern NiTPointerList <TESForm>	* g_quickKeyList;	//array of 8 NiTPointerLists of size 0-1 with pointers to hotkeyed items/spells

template <typename T>
class NiPointer
{
public:
	NiPointer(T *init) : data(init)		{	}

	T	* data;

	const T&	operator *() const { return *data; }
	T&			operator *() { return *data; }

	operator const T*() const { return data; }
	operator T*() { return data; }
};

// 1C
template <typename T>
class LockFreeMap
{
public:
	virtual void Unk_00(UInt32 arg0) = 0;
	virtual void Unk_01(UInt32 arg0, UInt32 arg1, UInt32 arg2) = 0;
	virtual void Unk_02(UInt32 arg0, UInt32 arg1, UInt32 arg2, UInt32 arg3, UInt32 arg4) = 0;
	virtual void Unk_03(UInt32 arg0, UInt32 arg1, UInt32 arg2, UInt32 arg3) = 0;
	virtual void Unk_04(UInt32 arg0, UInt32 agr1) = 0;
	virtual void Unk_05(UInt32 arg0, UInt32 comperand) = 0;
	virtual void Unk_06(UInt32 arg0) = 0;
	virtual void Unk_07(UInt32 arg0, UInt32 arg1) = 0;
	virtual void Unk_08(void) = 0;
	virtual void Unk_09(UInt32 arg0, UInt32 arg1) = 0;
	virtual void Unk_0A(UInt32 arg0, UInt32 arg1, UInt32 arg2, UInt32 arg3) = 0;
	virtual void Unk_0B(UInt32 arg0, UInt32 arg1, UInt32 arg2, UInt32 arg3) = 0;
	virtual void IncrementUnk0CCount(void) = 0;	
	virtual void DecrementUnk0CCount(void) = 0;		
	virtual UInt32 GetUnk0CCount(void) = 0;	

	void	* unk04;				// 004
	UInt32	unk0C_count;			// 008
	void	* unk0C;				// 00C has unk0C_count elements; init to 0
	UInt32	unk10;					// 010
	void	* unk14;				// 014 ptr to 0x10 byte struct
	UInt32	unk18;					// 018 init to 0
};

// 1C
template <typename T>
class LockFreeQueue
{
public:
	virtual void Unk_00(void) = 0;

	struct Node {
		Node	* next;
		T		data;
	};

	// void** vtbl
	Node	* head;						// 004 
	Node	* tail;						// 008
	UInt32	unk0C;						// 00C -init to c'tr arg1
	void	* unk10;					// 010 -dynamic alloc
	void	* unk14;					// 0x14 (0x10 byte struct, called with arg0)
	UInt32	unk18;						// 0x18 -init to 0
};