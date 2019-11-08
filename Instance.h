#pragma once
#include <G3DAll.h>
#include "propertyGrid.h"

class Instance
{
public:
	bool canDelete;
	Instance(void);
	Instance(const Instance&);
	virtual ~Instance(void);
	std::string name;
	virtual void render(RenderDevice*);
	virtual void update();
	std::string getClassName();
	Instance* findFirstChild(std::string);
	std::vector<Instance* > getChildren();
	std::vector<Instance* > getAllChildren();
	std::vector<Instance* > compileAndGetPVVector();
	virtual void setParent(Instance*);
	void setName(std::string newName);
	void addChild(Instance*);
	void removeChild(Instance*);
	void clearChildren();
	Instance* getParent();
	virtual Instance* clone() const { return new Instance(*this); }
	virtual std::vector<PROPGRIDITEM> getProperties();
	virtual void PropUpdate(LPPROPGRIDITEM &pItem);
	int listicon;
protected:
	std::vector<Instance*> children; // All children.
	std::string className;
	Instance* parent;  // Another pointer.
	PROPGRIDITEM createPGI(LPSTR catalog, LPSTR propName, LPSTR propDesc, LPARAM curVal, INT type, TCHAR choices[] = NULL);
	
};
