# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blavonne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 02:43:46 by blavonne          #+#    #+#              #
#    Updated: 2019/10/18 23:30:14 by blavonne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

i=1

for ((i = 1; i < 20; i++))
	do
		echo "Part 1. Test $i result:"
		./fillit maps1/test$i
		echo "____________\n"
	done

for ((i = 1; i < 17; i++))
	do
		echo "Part 2. Test $i result:"
		./fillit maps2/test$i
		echo "____________\n"
	done

for ((i = 1; i < 11; i++))
	do
		echo "Part 3. Test $i result:"
		time ./fillit maps3/test$i
		echo "____________\n"
	done
