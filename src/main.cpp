/*
    An universal parser for math-like expressions
    Copyright (C) 2019 ALXR aka loginsin
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>

// #define _DEBUG
#include "Controls.h"
#include "CMyParser.h"
#include <exception>

int main(int argc, char ** argv, char ** env)
{
	if ( argc < 2 )
	{
		printf(TEXT("ERROR: Missing expressions arguments!\n"));
		return 255;
	}

	CMyParser parser;
	for(int i = 1; i < argc; ++i)
	{
		try
		{
			TOK result;
			parser.Compile( argv[i] );
			parser.Evaluate();
			parser.Result( result );

			if ( abs(result.v.imag()) < 1e-15 )
			{
				printf(TEXT("%s = %Lf\n"), argv[i], result.v.real());
			}
			else
			{
				printf(TEXT("%s = %Lf%c%Lfi\n"),
					argv[i],
					result.v.real(),
					( result.v.imag() > 0 ? _T('+') : _T('-') ),
					std::abs( result.v.imag() ) );
			}
		}
		catch( CExprParserException & e )
		{
			printf(TEXT("Error evaluating: %s\n"), e.Message().GetString());
		}
		catch( std::exception & e )
		{
			printf(TEXT("Complex evaluating error!\n"));
		}
	}


	return 0;
}
