/** 
 *
 *
 *  \file      test_priva.c
 *  \author    Norbert
 *  \date      2017-01-06
 */
extern "C" {
#include	<priva/priva.h>
}
#include	<gtest/gtest.h>

TEST(PrivA,Result)
{
    ASSERT_EQ(42,PrivA_returnSomeNumber());
}
