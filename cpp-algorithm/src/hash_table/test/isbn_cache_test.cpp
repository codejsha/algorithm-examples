#include "isbn_cache.h"

#include "gtest/gtest.h"

TEST(IsIsbnInCache, TestInsertAndLookup)
{
    IsbnCache::LruCache cache(3);
    cache.Insert("978-0262033848", 99);
    cache.Insert("978-1260091991", 99);
    cache.Insert("978-0984782857", 40);
    EXPECT_EQ(cache.Lookup("978-0262033848"), 99);
    EXPECT_EQ(cache.Lookup("978-1260091991"), 99);
}

TEST(IsIsbnInCache, TestRemoveLru)
{
    IsbnCache::LruCache cache(3);
    cache.Insert("978-0262033848", 99);
    cache.Insert("978-1260091991", 99);
    cache.Insert("978-0984782857", 40);
    EXPECT_EQ(cache.Erase("978-1260091991"), true);
    EXPECT_EQ(cache.Erase("978-0984782857"), true);
}

TEST(IsIsbnInCache, TestErase)
{
    IsbnCache::LruCache cache(2);
    cache.Insert("978-0262033848", 99);
    cache.Insert("978-1260091991", 99);
    cache.Erase("978-1260091991");
    EXPECT_EQ(cache.Lookup("978-1260091991"), -1);
    EXPECT_EQ(cache.Lookup("978-0262033848"), 99);
}

TEST(IsIsbnInCache, TestEraseNonexistent)
{
    IsbnCache::LruCache cache(2);
    cache.Insert("978-0262033848", 99);
    cache.Insert("978-1260091991", 99);
    EXPECT_EQ(cache.Erase("978-0000000000"), false);
}
