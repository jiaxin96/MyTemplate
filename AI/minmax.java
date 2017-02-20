    int max_val(int[] nums , int pb, int startpos, int endpos, int dp) {
        int alpha = -INF;
        int beta = pb;

        if (startpos == endpos) {

            wins =  (maxp+startpos > minp);

            if (dp == 0) {
                value_g = maxp + nums[startpos] - minp;
            }

            return maxp + nums[startpos] - minp;
        }

        int [] step = new int[] {startpos, endpos};

        int t = -INF;

        for (int i : step) {


            // set( maxp, i);
            maxp += nums[i];

            if (i == startpos) {
                t = min_val(nums, alpha, startpos + 1, endpos, dp+1);
            }
            else {
                t = min_val(nums, alpha, startpos, endpos - 1, dp+1);
            }

            // rollback( maxp, i);
            maxp -= nums[i];


            if (value_g > 0) {
                alpha = INF;
                break;
            }

            if (t > alpha) {
                alpha = t;
            }


            if (alpha >= beta) {
                break;
            }

        }



        return alpha;

    }


    int min_val(int[] nums, int pa, int startpos, int endpos, int dp) {
        int beta = INF;
        int alpha = pa;

        if (startpos == endpos) {

            wins =  (maxp > minp+startpos);

            return maxp - nums[startpos] - minp;
        }

        int [] step = new int[]{startpos, endpos};

        int t= INF;

        for (int i : step) {

            // set( minp, i);
            minp += nums[i];


            if (i == startpos) {
                t = max_val(nums, beta, startpos + 1, endpos, dp+1);
            }
            else {
                t = max_val(nums, beta, startpos, endpos - 1, dp+1);
            }


            // rollback(minp, i);
            minp -= nums[i];

            if (value_g < 0) {
                alpha = -INF;
                break;
            }

            if (t < beta) {
                beta = t;
            }

            if (alpha >= beta) {
                break;
            }

        }


        return beta;

    }