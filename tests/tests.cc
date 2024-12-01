//
// Created by Светлана Пислякова on 28.11.2024.
//

#include <gtest/gtest.h>
#include "../core/Segment3D.h"
#include "../core/Vector3D.h"


TEST(Intersect, Test_1) {
    Vector3D first_start(2, 2, 2), first_end(2, 2, 2);
    Vector3D second_start(1, 2, 0), second_end(1, 2, 0);
    Segment3D first(first_start, first_end), second(second_start, second_end);
    try {
        first.Intersect(second);
    } catch (const std::runtime_error& e) {
        ASSERT_STREQ("Оба отрезка вырождены в точку и не совпадают", e.what());
    }
}

TEST(Intersect, Test_2) {
    Vector3D first_start(2, 2, 2), first_end(2, 2, 2);
    Vector3D second_start(2, 2, 2), second_end(2, 2, 2);
    Segment3D first(first_start, first_end), second(second_start, second_end);
    Vector3D result(2, 2, 2);
    ASSERT_EQ(Intersect(first, second), result);
}

TEST(Intersect, Test_3) {
    Vector3D first_start(2, 2, 2), first_end(2, 2, 2);
    Vector3D second_start(3, 3, 3), second_end(10, 10, 10);
    Segment3D first(first_start, first_end), second(second_start, second_end);
    try {
        first.Intersect(second);
    } catch (const std::runtime_error& e) {
        ASSERT_STREQ("Один из отрезков вырожден в точку и не совпадает со вторым", e.what());
    }
}

TEST(Intersect, Test_4) {
    Vector3D first_start(2, 2, 2), first_end(2, 2, 2);
    Vector3D second_start(1, 1, 1), second_end(3, 3, 3);
    Segment3D first(first_start, first_end), second(second_start, second_end);
    Vector3D result(2, 2, 2);
    ASSERT_EQ(Intersect(first, second), result);
}

TEST(Intersect, Test_5) {
    Vector3D first_start(3, 3, 3), first_end(10, 10, 10);
    Vector3D second_start(2, 2, 2), second_end(2, 2, 2);
    Segment3D first(first_start, first_end), second(second_start, second_end);
    try {
        first.Intersect(second);
    } catch (const std::runtime_error& e) {
        ASSERT_STREQ("Один из отрезков вырожден в точку и не совпадает со вторым", e.what());
    }
}

TEST(Intersect, Test_6) {
    Vector3D first_start(1, 1, 1), first_end(3, 3, 3);
    Vector3D second_start(2, 2, 2), second_end(2, 2, 2);
    Segment3D first(first_start, first_end), second(second_start, second_end);
    Vector3D result(2, 2, 2);
    ASSERT_EQ(Intersect(first, second), result);
}

TEST(Intersect, Test_7) {
    Vector3D first_start(10, 10, 0), first_end(0, 0, 0);
    Vector3D second_start(4, 1, 0), second_end(4, 10, 0);
    Segment3D first(first_start, first_end), second(second_start, second_end);
    Vector3D result(4, 4, 0);
    ASSERT_EQ(Intersect(first, second), result);
}

TEST(Intersect, Test_8) {
    Vector3D first_start(10, 10, 0), first_end(0, 0, 0);
    Vector3D second_start(11, 1, 0), second_end(11, 20, 0);
    Segment3D first(first_start, first_end), second(second_start, second_end);
    try {
        first.Intersect(second);
    } catch (const std::runtime_error& e) {
        ASSERT_STREQ("Отрезки не пересекаются", e.what());
    }
}

TEST(Intersect, Test_9) {
    Vector3D first_start(10, 10, 0), first_end(0, 0, 0);
    Vector3D second_start(11, 1, 2), second_end(11, 20, 2);
    Segment3D first(first_start, first_end), second(second_start, second_end);
    try {
        first.Intersect(second);
    } catch (const std::runtime_error& e) {
        ASSERT_STREQ("Отрезки не пересекаются", e.what());
    }
}

TEST(Intersect, Test_10) {
    Vector3D first_start(0, 0, 0), first_end(12, 12, 0);
    Vector3D second_start(4, 0, 0), second_end(12, 8, 0);
    Segment3D first(first_start, first_end), second(second_start, second_end);
    try {
        first.Intersect(second);
    } catch (const std::runtime_error& e) {
        ASSERT_STREQ("Отрезки не пересекаются", e.what());
    }
}

TEST(Intersect, Test_11) {
    Vector3D first_start(0, 0, 0), first_end(5, 5, 0);
    Vector3D second_start(6, 6, 0), second_end(12, 12, 0);
    Segment3D first(first_start, first_end), second(second_start, second_end);
    try {
        first.Intersect(second);
    } catch (const std::runtime_error& e) {
        ASSERT_STREQ("Отрезки не пересекаются", e.what());
    }
}

TEST(Intersect, Test_12) {
    Vector3D first_start(0, 0, 0), first_end(10, 10, 0);
    Vector3D second_start(6, 6, 0), second_end(12, 12, 0);
    Segment3D first(first_start, first_end), second(second_start, second_end);
    try {
        first.Intersect(second);
    } catch (const std::runtime_error& e) {
        ASSERT_STREQ("Отрезки совпадают полностью либо частично", e.what());
    }
}

TEST(Intersect, Test_13) {
    Vector3D first_start(0, 0, 0), first_end(6, 6, 0);
    Vector3D second_start(6, 6, 0), second_end(12, 12, 0);
    Segment3D first(first_start, first_end), second(second_start, second_end);
    Vector3D result(6, 6, 0);
    ASSERT_EQ(Intersect(first, second), result);
}

TEST(Intersect, Test_14) {
    Vector3D first_start(0, 0, 0), first_end(6, 6, 0);
    Vector3D second_start(12, 12, 0), second_end(6, 6, 0);
    Segment3D first(first_start, first_end), second(second_start, second_end);
    Vector3D result(6, 6, 0);
    ASSERT_EQ(Intersect(first, second), result);
}

TEST(Intersect, Test_15) {
    Vector3D first_start(6, 6, 0), first_end(0, 0, 0);
    Vector3D second_start(6, 6, 0), second_end(12, 12, 0);
    Segment3D first(first_start, first_end), second(second_start, second_end);
    Vector3D result(6, 6, 0);
    ASSERT_EQ(Intersect(first, second), result);
}

TEST(Intersect, Test_16) {
    Vector3D first_start(6, 6, 0), first_end(0, 0, 0);
    Vector3D second_start(12, 12, 0), second_end(6, 6, 0);
    Segment3D first(first_start, first_end), second(second_start, second_end);
    Vector3D result(6, 6, 0);
    ASSERT_EQ(Intersect(first, second), result);
}
