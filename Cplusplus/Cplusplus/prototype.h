#include <memory>

using namespace std;

class Record
{
public:
	virtual ~Record();
	virtual void print() = 0;
	virtual unique_ptr<Record> clone() = 0;
private:

};

enum RecordType
{
	CAR,
	BIKE,
	PERSON
};


/** RecordFactory is the client */
class RecordFactory
{
private:
	unordered_map<RecordType, unique_ptr<Record>, hash<int> > m_records;

public:

	unique_ptr<Record> createRecord(RecordType recordType)
	{
		return m_records[recordType]->clone();
	}
};