// Field class definition file.

#include "simulation/fields/Field.h"
#include "simulation/grid/Cell.h"
#include "simulation/grid/Grid2D.h"

namespace sim {

    Field::Field(Grid2D& grid) :
        grid_(&grid)
    {}

    Field::Field(const Field& other)
    {
        grid_ = new Grid2D(*other.grid_);
    }

    Field::~Field()
    {
        delete grid_;
    }

    Cell& Field::at(std::size_t x, std::size_t y) 
    {
        return grid_->getCell(x, y); 
    }

    const Cell& Field::at(std::size_t x, std::size_t y) const 
    { 
        return grid_->getCell(x, y); 
    }

    std::size_t Field::getWidth() const 
    { 
        return grid_->getWidth(); 
    }

    std::size_t Field::getHeight() const 
    { 
        return grid_->getHeight(); 
    }

    float Field::getCellSize() const 
    { 
        return grid_->getCellSize(); 
    }

    Field& Field::operator=(const Field& other) 
    {
        if (this != &other)
            *grid_ = *other.grid_;

        return *this;
    }

    void Field::move(Field& other)
    {
        
    }

}