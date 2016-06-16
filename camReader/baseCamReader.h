#pragma once
#ifndef BASECAMREADER_H
class baseCamReader
{
public:
	baseCamReader() {}
	~baseCamReader() {}

	virtual void Init() {}
	virtual void Input() {}
	virtual void Tick() {}
	virtual void Output() {}
	virtual void Exit() {}
};
#endif // !BASECAMREADER_H