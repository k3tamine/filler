# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    stat.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgonon <mgonon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 17:33:49 by mgonon            #+#    #+#              #
#    Updated: 2017/10/25 21:49:21 by mgonon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

declare -a players=('abanlin' 'carli' 'champely' 'grati' 'hcao' 'superjeannot');
# declare -a maps=('00' '01' '02');
declare -a maps=('00' '01');

your_player=mgonon.filler
i=0
a='p2'
b='p1'

# while [ $i < 2 ]; do
# 	if [ $i == 1 ]; then
# 		a='p2'
# 		b='p1'
# 	fi
# 	((i++))
	for player in "${players[@]}"; do
		# echo "=== $your_player vs $player ===\n"
		for map in "${maps[@]}"; do
			n_turns=2
			if [ $map == '00' ]; then
				n_turns=100
			elif [ $map == '01' ]; then
				n_turns=40
			elif [ $map == '02' ]; then
				n_turns=15
			fi
			p1=0
			p2=0
			echo "=== map$map ==="
			while [ $n_turns != 0 ]; do
				# echo "player = $player"
				./filler_vm -f ./maps/map$map -$a \
					./players/$your_player -$b \
					./players/$player.filler > /dev/null
					# ./players/$player2 > /dev/null
				result=$(cat filler.trace | grep won)
				if echo "$result" | grep -q "$your_player"
				then
					((p1++))
				else
					((p2++))
				fi
				((n_turns--))
			done
			echo $your_player
			echo $p1
			echo $player
			echo $p2
		done
		echo "\n"
	done
# done

# player1=mgonon.filler
# player2=abanlin.filler

# n_turns=15
# map=02

# p1=0;
# p2=0;

# while [ $n_turns != 0 ]
# do
# 	./filler_vm -f ./maps/map$map -p1 \
# 		./players/$player1 -p2 \
# 		./players/$player2 >> toto
# 		# ./players/$player2 > /dev/null
# 	result=$(cat filler.trace | grep won)
# 	if echo "$result" | grep -q "$player1"
# 	then
# 		((p1++))
# 	else
# 		((p2++))
# 	fi
# 	((n_turns--))
# done

# echo $player1
# echo $p1
# echo $player2
# echo $p2
