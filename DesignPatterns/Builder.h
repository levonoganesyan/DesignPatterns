#pragma once

#include<string>
#include<memory>
#include<iostream>


struct Cake
{
    int cream;
    int dough;
    int candy;
    int heart;
};


struct CakeRecipe
{
    std::string recipe;
};

class Builder
{
public:
    virtual void Reset() = 0;
    virtual void AddCream() = 0;
    virtual void AddDough() = 0;
    virtual void AddCandies() = 0;
    virtual void AddHearts() = 0;
};


class CakeBuilder : public Builder
{
    std::shared_ptr<Cake> cake;
public:
    CakeBuilder(std::shared_ptr<Cake> cake)
        : cake(cake)
    {

    }
    virtual void Reset()
    {
        cake->candy = 0;
        cake->cream = 0;
        cake->dough = 0;
        cake->heart = 0;
    }
    virtual void AddCream()
    {
        cake->cream++;
    }
    virtual void AddDough()
    {
        cake->dough++;
    }
    virtual void AddCandies()
    {
        cake->candy++;
    }
    virtual void AddHearts()
    {
        cake->heart++;
    }

};



class CakeRecipeBuilder : public Builder
{
    std::shared_ptr<CakeRecipe> cake;
public:
    CakeRecipeBuilder(std::shared_ptr<CakeRecipe> cake)
        : cake(cake)
    {

    }
    virtual void Reset()
    {
        cake->recipe = "";
    }
    virtual void AddCream()
    {
        cake->recipe += "Adding some cream.\n";
    }
    virtual void AddDough()
    {
        cake->recipe += "Adding some dough.\n";
    }
    virtual void AddCandies()
    {
        cake->recipe += "Adding some candies.\n";
    }
    virtual void AddHearts()
    {
        cake->recipe += "Adding some hearts.\n";
    }

};

class Chef
{
public:
    void createSmallCake(Builder& builder)
    {
        builder.Reset();
        builder.AddDough();
        builder.AddCream();
    }
    void createValentineCake(Builder& builder)
    {
        builder.Reset();
        builder.AddDough();
        builder.AddCream();
        builder.AddCandies();
        builder.AddHearts();
        builder.AddHearts();
        builder.AddHearts();
        builder.AddHearts();
    }
};

void Print(std::shared_ptr<Cake> c)
{
    std::cout << "\ncandy = " << c->candy
            << "\ncream = " << c->cream
            << "\ndough = " << c->dough
            << "\nhearths = " << c->heart << std::endl;
}

void Test()
{
    std::shared_ptr<Cake> c = std::make_shared<Cake>();
    Builder* cake = new CakeBuilder(c);
    Chef chef;
    chef.createSmallCake(*cake);
    Print(c);
    chef.createValentineCake(*cake);
    Print(c);
    std::shared_ptr<CakeRecipe> cr = std::make_shared<CakeRecipe>();
    cake = new CakeRecipeBuilder(cr);
    chef.createValentineCake(*cake);
    std::cout << cr->recipe << std::endl;



}
