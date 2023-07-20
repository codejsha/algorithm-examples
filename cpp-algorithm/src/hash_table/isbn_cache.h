#ifndef CPP_ALGORITHM_ISBN_CACHE_H
#define CPP_ALGORITHM_ISBN_CACHE_H

#include <list>
#include <string>
#include <unordered_map>

namespace IsbnCache
{
    /**
     * \brief Least recently used cache for ISBNs.
     */
    class LruCache
    {
    public:
        LruCache(size_t capacity) {}

        explicit LruCache(int capacity)
            : capacity_(capacity) {}

        /**
         * \brief Lookup ISBN in cache.
         * \param isbn the ISBN to search for
         * \return price if the ISBN is in the cache, -1 otherwise
         */
        auto Lookup(const std::string& isbn) -> int
        {
            if (auto it = price_table_.find(isbn); it == price_table_.end())
            {
                return -1;
            }
            else
            {
                auto price = it->second.second;
                MoveToFront(isbn, it);
                return price;
            }
        }

        /**
         * \brief Insert an ISBN into the cache.
         * \param isbn the ISBN to insert
         * \param price the price of the book
         */
        void Insert(const std::string& isbn, int price)
        {
            if (auto it = price_table_.find(isbn); it != price_table_.end())
            {
                MoveToFront(isbn, it);
            }
            else
            {
                if (price_table_.size() == capacity_)
                {
                    price_table_.erase(lru_queue_.back());
                    lru_queue_.pop_back();
                }
                lru_queue_.emplace_front(isbn);
                price_table_[isbn] = {lru_queue_.begin(), price};
            }
        }

        /**
         * \brief Erase an ISBN from the cache.
         * \param isbn the ISBN to erase
         * \return true if the ISBN was in the cache, false otherwise
         */
        auto Erase(const std::string& isbn) -> bool
        {
            if (auto it = price_table_.find(isbn); it == price_table_.end())
            {
                return false;
            }
            else
            {
                lru_queue_.erase(it->second.first);
                price_table_.erase(it);
                return true;
            }
        }

    private:
        using Table = std::unordered_map<std::string, std::pair<std::list<std::string>::iterator, int>>;

        /**
         * \brief Move an ISBN to the front of the queue.
         * \param isbn the ISBN to move
         * \param it the iterator to the ISBN in the queue
         */
        void MoveToFront(const std::string& isbn, const Table::iterator& it)
        {
            lru_queue_.erase(it->second.first);
            lru_queue_.emplace_front(isbn);
            it->second.first = lru_queue_.begin();
        }

        int capacity_;
        Table price_table_;
        std::list<std::string> lru_queue_;
    };
}

#endif
