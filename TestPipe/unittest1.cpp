#include "stdafx.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestPipe
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Testv1)
		{
			// TODO: Разместите здесь код своего теста
			Pipe p = Pipe();
			std::string cool[][2] = { { "a", "" },{ "b", "a" },{ "c", "a" },{ "d", "a" },{ "f", "a" },{ "e", "c" },{ "k","fed" },{ "g","fed" },{ "m","fed" },{ "h","g" },{ "n","khm" },{ "p","bn" } };
			Assert::AreEqual(p.CheckPipe(cool, std::size(cool), p.ReadPipe("")), true);
		}
		TEST_METHOD(Testv2)
		{
			// TODO: Разместите здесь код своего теста
			Pipe p = Pipe();
			std::string cool[][2] = { { "a", "" },{ "b", "" },{ "c", "a" },{ "d", "a" },{ "e", "a" },{ "g", "cb" },{ "f","d" },{ "h","bc" },{ "i","bc" },{ "k","hgfe" },{ "m","hgfe" },{ "n","ikm" } };
			Assert::AreEqual(p.CheckPipe(cool, std::size(cool), p.ReadPipe("")),true );
		}
		TEST_METHOD(Testv3)
		{
			// TODO: Разместите здесь код своего теста
			Pipe p = Pipe();
			std::string cool[][2] = { { "a", "" },{ "b", "" },{ "d", "" },{ "c", "a" },{ "e", "cb" },{ "f", "cb" },{ "h","cb" },{ "g","ed" },{ "i","fg" },{ "k","fg" },{ "m","hi" }};
			Assert::AreEqual(p.CheckPipe(cool, std::size(cool), p.ReadPipe("")), true);
		}
		TEST_METHOD(Testv4)
		{
			// TODO: Разместите здесь код своего теста
			Pipe p = Pipe();
			std::string cool[][2] = { { "a", "" },{ "c", "" },{ "d", "" },{ "e", "" },{ "b", "a" },{ "g", "cb" },{ "f","d" },{ "h","bc" },{ "i","gfe" },{ "k","gfe" },{ "m","hik" }};
			Assert::AreEqual(p.CheckPipe(cool, std::size(cool), p.ReadPipe("")), true);
		}
		TEST_METHOD(Testv5)
		{
			// TODO: Разместите здесь код своего теста
			Pipe p = Pipe();
			std::string cool[][2] = { { "a", "" },{ "c", "" },{ "g", "a" },{ "e", "a" },{ "b", "a" },{ "f", "e" },{ "d","b" },{ "h","fdc" },{ "i","hg" },{ "k","fdc" },{ "m","gh" },{ "n","ik" } };
			Assert::AreEqual(p.CheckPipe(cool, std::size(cool), p.ReadPipe("")), true);
		}
		TEST_METHOD(Testv6)
		{
			// TODO: Разместите здесь код своего теста
			Pipe p = Pipe();
			std::string cool[][2] = { { "a", "" },{ "b", "a" },{ "c", "a" },{ "d", "a" },{ "e", "c" },{ "g", "b" },{ "f","e" },{ "h","de" },{ "i","fg" },{ "k","fg" },{ "m","hi" }};
			Assert::AreEqual(p.CheckPipe(cool, std::size(cool), p.ReadPipe("")), true);
		}
		TEST_METHOD(Testv7)
		{
			// TODO: Разместите здесь код своего теста
			Pipe p = Pipe();
			std::string cool[][2] = { { "a", "" },{ "b", "a" },{ "c", "a" },{ "d", "a" },{ "e", "b" },{ "g", "a" },{ "f","ec" },{ "i","ec" },{ "k","fd" },{ "m","fd" },{ "n","gik" } };
			Assert::AreEqual(p.CheckPipe(cool, std::size(cool), p.ReadPipe("")), true);
		}
		TEST_METHOD(Testv8)
		{
			// TODO: Разместите здесь код своего теста
			Pipe p = Pipe();
			std::string cool[][2] = { { "a", "" },{ "b", "a" },{ "c", "a" },{ "d", "bc" },{ "e", "a" },{ "g", "bc" },{ "f","ed" },{ "h","ed" },{ "i","f" } };
			Assert::AreEqual(p.CheckPipe(cool, std::size(cool), p.ReadPipe("")), true);
		}
		TEST_METHOD(Testv9)
		{
			// TODO: Разместите здесь код своего теста
			Pipe p = Pipe();
			std::string cool[][2] = { { "a", "" },{ "b", "" },{ "c", "" },{ "d", "a" },{ "e", "db" },{ "g", "f" },{ "f","ce" },{ "h","ce" },{ "i","ce" },{ "k","gh" } };
			Assert::AreEqual(p.CheckPipe(cool, std::size(cool), p.ReadPipe("")), true);
		}
		TEST_METHOD(Testv10)
		{
			// TODO: Разместите здесь код своего теста
			Pipe p = Pipe();
			std::string cool[][2] = { { "a", "" },{ "b", "a" },{ "c", "" },{ "d", "" },{ "e", "" },{ "g", "cb" },{ "f","cb" },{ "h","fe" },{ "i","fe" },{ "k","dgh" },{ "m","ki" } };
			Assert::AreEqual(p.CheckPipe(cool, std::size(cool), p.ReadPipe("")), true);
		}
		TEST_METHOD(Testv11)
		{
			// TODO: Разместите здесь код своего теста
			Pipe p = Pipe();
			std::string cool[][2] = { { "a", "" },{ "b", "a" },{ "c", "a" },{ "d", "" },{ "e", "a" },{ "g", "f" },{ "f","b" },{ "h","ge" },{ "i","ge" },{ "k","ge" },{ "m","ihd" } };
			Assert::AreEqual(p.CheckPipe(cool, std::size(cool), p.ReadPipe("")), true);
		}
		TEST_METHOD(Testv12)
		{
			// TODO: Разместите здесь код своего теста
			Pipe p = Pipe();
			std::string cool[][2] = { { "a", "" },{ "b", "a" },{ "c", "a" },{ "d", "c" },{ "e", "b" },{ "g", "b" },{ "f","b" },{ "h","def" },{ "i","def" },{ "k","ihg" } };
			Assert::AreEqual(p.CheckPipe(cool, std::size(cool), p.ReadPipe("")), true);
		}
		TEST_METHOD(Testv13)
		{
			// TODO: Разместите здесь код своего теста
			Pipe p = Pipe();
			std::string cool[][2] = { { "a", "" },{ "b", "a" },{ "c", "a" },{ "d", "b" },{ "e", "b" },{ "g", "fc" },{ "f","b" },{ "h","fc" },{ "i","kdg" },{ "k","e" },{ "m","e" },{ "n","mih" } };
			Assert::AreEqual(p.CheckPipe(cool, std::size(cool), p.ReadPipe("")), true);
		}
		TEST_METHOD(Testv14)
		{
			// TODO: Разместите здесь код своего теста
			Pipe p = Pipe();
			std::string cool[][2] = { { "a", "" },{ "b", "" },{ "c", "a" },{ "d", "b" },{ "e", "b" },{ "g", "e" },{ "f","dc" },{ "h","e" },{ "p","g" },{ "k","hf" },{ "m","hf" },{ "n","pk" } };
			Assert::AreEqual(p.CheckPipe(cool, std::size(cool), p.ReadPipe("")), true);
		}
		TEST_METHOD(Testv15)
		{
			// TODO: Разместите здесь код своего теста
			Pipe p = Pipe();
			std::string cool[][2] = { { "a", "" },{ "b", "a" },{ "c", "a" },{ "d", "" },{ "e", "c" },{ "g", "a" },{ "f","b" },{ "h","a" },{ "i","g" },{ "k","g" },{ "m","hkif" },{ "n","d" },{ "p","me" } };
			Assert::AreEqual(p.CheckPipe(cool, std::size(cool), p.ReadPipe("")), true);
		}
		TEST_METHOD(Testv16)
		{
			// TODO: Разместите здесь код своего теста
			Pipe p = Pipe();
			std::string cool[][2] = { { "a", "" },{ "b", "a" },{ "c", "a" },{ "e", "a" },{ "g", "c" },{ "f","a" },{ "h","bd" },{ "i","g" },{ "k","he" } };
			Assert::AreEqual(p.CheckPipe(cool, std::size(cool), p.ReadPipe("")), true);
			
		}
		TEST_METHOD(Testv17)
		{
			// TODO: Разместите здесь код своего теста
			Pipe p = Pipe();
			std::string cool[][2] = { { "a", "" },{ "b", "" },{ "c", "a" },{ "d", "" },{ "e", "bc" },{ "g", "ed" },{ "f","bc" },{ "h","bc" },{ "i","fg" },{ "k","fg" },{ "m","hi" }};
			Assert::AreEqual(p.CheckPipe(cool, std::size(cool), p.ReadPipe("")), true);
		}
		TEST_METHOD(Testv18)
		{
			// TODO: Разместите здесь код своего теста
			Pipe p = Pipe();
			std::string cool[][2] = { { "a", "" },{ "b", "" },{ "c", "a" },{ "d", "a" },{ "e", "c" },{ "g", "e" },{ "f","d" },{ "h","bgf" },{ "i","" },{ "k","bgf" },{ "m","khi" } };
			Assert::AreEqual(p.CheckPipe(cool, std::size(cool), p.ReadPipe("")), true);
		}
		TEST_METHOD(Testv19) //НЕПОЛНО
		{
			// TODO: Разместите здесь код своего теста
			Pipe p = Pipe();
			std::string cool[][2] = { { "a", "" },{ "b", "a" },{ "c", "a" },{ "d", "a" },{ "e", "b" },{ "g", "cb" },{ "f","d" },{ "h","bc" },{ "i","bc" },{ "k","hgfe" },{ "m","hgfe" },{ "n","ikm" } };
			Assert::AreEqual(p.CheckPipe(cool, std::size(cool), p.ReadPipe("")), true);
		}
		TEST_METHOD(Testv20)
		{
			// TODO: Разместите здесь код своего теста
			Pipe p = Pipe();
			std::string cool[][2] = { { "a", "" },{ "b", "a" },{ "c", "a" },{ "d", "b" },{ "e", "b" },{ "g", "b" },{ "f","a" },{ "h","dc" },{ "i","h" },{ "k","eri" },{ "m","hf" },{ "n","hf" },{ "r","dc" },{ "p","km" } };
			Assert::AreEqual(p.CheckPipe(cool, std::size(cool), p.ReadPipe("")), true);
		}

	};
}