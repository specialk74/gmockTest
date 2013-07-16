#include "gmock/gmock.h"    //<label id="code.include"/>
#include "Soundex.h"

using namespace testing;

class SoundexEncoding: public Test {
				public:
								Soundex soundex;								
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) { //<label id="code.test"/>
	ASSERT_THAT(soundex.encode("A"), Eq("A000")); // Assert that the encode of "A" value is equal to the string "A000"
}

TEST_F(SoundexEncoding, PadsWithZeroToEnsureThreeDigits) {
	ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropiateDigits) {
	ASSERT_THAT(soundex.encode("Ax"), Eq("A200"));
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetics) {
	ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits) {
	ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}

TEST_F(SoundexEncoding, LimitsLenghtToFourCharacters) {
					ASSERT_THAT(soundex.encode("Dcdlb").length(), Eq(4u));
}
