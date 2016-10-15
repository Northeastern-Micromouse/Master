#include "gtest/gtest.h"

extern "C" {
	#include "src/main/c/com/micromouse/utility/list/list.h"
}

TEST(ListTests, ShouldInitializeANodeCorreectly) {
	// Given: a cell containing data.
	Cell * cell = InitializeCell(10, 10);

	// When: initializing a list
	List * list = InitializeList(cell);

	// Then: the data should be initialized correctly.
	EXPECT_EQ(10, list->data_->location->x);
	EXPECT_EQ(10, list->data_->location->y);
	EXPECT_EQ(true, list->data_->top);
	EXPECT_EQ(true, list->data_->bottom);
	EXPECT_EQ(true, list->data_->left);
	EXPECT_EQ(true, list->data_->right);
	EXPECT_EQ(false, list->data_->mapped);
	EXPECT_EQ(false, list->data_->visited);
	EXPECT_EQ(true, list->data_->open);

	// Free the memory.
	ListDestructor(list);
}

TEST(ListTests, AnEmptyListSholudHaveASizeOfZero) {
	// Given: an empty list
	List * list = NULL;

	// then: the size should be zero.
	EXPECT_EQ(0, length(list));
}

TEST(ListTests, AListOfSizeOneShouldHaveSizeOne) {
	// Given: a list of size one
	Cell * cell = InitializeCell(10, 10);
	List * list = InitializeList(cell);

	// then: the size should be one.
	EXPECT_EQ(1, length(list));

	// Free the memory.
	ListDestructor(list);
}

TEST(ListTests, AListOfSizeTwoShouldHaveSizeTwo) {
	// Given: a list of size two.
	Cell * cell_one = InitializeCell(1, 1);
	Cell * cell_two = InitializeCell(3, 3);
	List * list = InitializeList(cell_one);
	PushBack(cell_two, list);

	// then: the size should be two.
	EXPECT_EQ(2, length(list));

	// Free the memory.
	ListDestructor(list);
}
