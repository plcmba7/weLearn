#pragma once

#ifndef BASECAMREADER_H
#define BASECAMREADER_H

/// Abstract base class that acts the interface.
/// Note: If you are deriving from this class, implement the virtual methods ( at least a dummy implementation
/// is necessary) 

class baseCamReader
{
public:
	baseCamReader() {}
	~baseCamReader() {}

	virtual void Init() = 0;
	virtual void Input() = 0;
	virtual void Tick() = 0;
	virtual void Output() = 0;
	virtual void Exit() = 0;
};
#endif // !BASECAMREADER_H