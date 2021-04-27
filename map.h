#ifndef MAP_H
#define MAP_H


class Map
{
public:
    Map();
    ~Map();

    enum map_fields {
        wall,
        score_point,
        fruit,
        none
    };

    int getMap_height() const;

    int getMap_width() const;

    int getScore_point_number() const;
    void score_point_number_decrement();

    map_fields getMapAtPosition(int x, int y) const;
    void setMapAtPosition(int x, int y, map_fields value);

private:
    const int map_height;
    const int map_width;
    int score_point_number;

    map_fields** map;
};

#endif // MAP_H
