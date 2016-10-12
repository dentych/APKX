//
// Created by dennis on 12/10/16.
//

#pragma once

class BagageGen {
public:
    BagageGen();

    void nextBagage();
private:
    std::vector<std::shared_ptr<Bagage>> bagageList;
};
